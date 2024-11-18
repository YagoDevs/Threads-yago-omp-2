cmake_minimum_required(VERSION 3.29)
project(threads)

set(CMAKE_CXX_STANDARD 20)

add_executable(threads main.cpp)

find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    target_compile_options(threads PRIVATE -fopenmp)
    target_link_options(threads PRIVATE -fopenmp)
endif()
