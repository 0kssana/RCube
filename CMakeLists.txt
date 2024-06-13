cmake_minimum_required(VERSION 3.25.1)
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

add_custom_command(TARGET RCube POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/RCube/Cubein.txt
        $<TARGET_FILE_DIR:RCube>/Cubein.txt)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(RCube PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT)