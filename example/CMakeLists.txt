cmake_minimum_required(VERSION 3.10)

project(abr-example)

add_subdirectory(
    3rd_party/ABR
)

list(APPEND EXTRA_LIBS abr)

add_executable(abr-example
    src/example.c
)

target_link_libraries(abr-example PUBLIC ${EXTRA_LIBS})

