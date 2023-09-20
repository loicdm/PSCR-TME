cmake_minimum_required(VERSION 3.26)
project(TME1)

set(CMAKE_CXX_STANDARD 14)

include_directories(exo1/src)

add_executable(TME1
        exo1/src/List.cpp
        exo1/src/List.h
        exo1/src/main.cpp)
