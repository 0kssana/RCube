cmake_minimum_required(VERSION 3.28)
project(RCube)

set(CMAKE_CXX_STANDARD 11)

include_directories(RCube)

add_executable(RCube
        RCube/cube_base.h
        RCube/glcube.h
        RCube/main.cpp)