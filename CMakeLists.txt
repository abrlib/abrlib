cmake_minimum_required(VERSION 3.10)

project(abruslib VERSION 0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Static lib
add_library(abruslib STATIC
    src/abruslib.c
)
target_include_directories(abruslib
    PUBLIC include
    PRIVATE src
)

# Static lib
add_library(abruslib-shared SHARED
    src/abruslib.c
)
target_include_directories(abruslib-shared
    PUBLIC include
    PRIVATE src
)
