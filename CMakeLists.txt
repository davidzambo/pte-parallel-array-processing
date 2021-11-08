cmake_minimum_required(VERSION 3.20)
project(parallel-array-processing)


set(CMAKE_C_STANDARD 99)

add_executable(parallel-array-processing src/main.c src/usage.c src/usage.h src/param_handling.c src/param_handling.h src/file_processing.c src/file_processing.h src/array_initialization.c src/array_initialization.h)