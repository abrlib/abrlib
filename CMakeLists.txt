cmake_minimum_required(VERSION 3.10)

project(abr VERSION 0.0)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

add_library(abr STATIC
    src/abr.c
)

target_include_directories(abr
    PUBLIC include
    PRIVATE src
)