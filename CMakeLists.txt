cmake_minimum_required(VERSION 3.28)
project(RCube)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RCube
        RCube/cube.h
        RCube/cube_realization.cpp
        RCube/main.cpp
        RCube/rotations.cpp
        RCube/solver.cpp
        RCube/visual_cube.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(RCube PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT)