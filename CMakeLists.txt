cmake_minimum_required(VERSION 3.10)

project(abr VERSION 0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Static lib
add_library(abrlib STATIC
    src/abrlib.c
)
target_include_directories(abrlib
    PUBLIC include
    PRIVATE src
)

# Static lib
add_library(abrlib-shared SHARED
    src/abrlib.c
)
target_include_directories(abrlib-shared
    PUBLIC include
    PRIVATE src
)
