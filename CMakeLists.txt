cmake_minimum_required(VERSION 3.25.1)
project(RCube)

set(CMAKE_CXX_STANDARD 11)

include_directories(RCube)

add_executable(RCube
        RCube/cube_base.h
        RCube/glcube.cpp
        RCube/glcube.h
        RCube/main.cpp
        RCube/solver.cpp
        RCube/solver.h)

add_custom_command(TARGET RCube POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/RCube/storage.txt
        $<TARGET_FILE_DIR:RCube>/storage.txt)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(RCube PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT)
