cmake_minimum_required(VERSION 3.25.1)
project(RCube)

add_subdirectory(doctest)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RCube
        RCube/cube.h
        RCube/cube_realization.cpp
        RCube/main.cpp
        RCube/rotations.cpp
        RCube/solver.cpp
        RCube/visual_cube.cpp
        RCubeTests/MockCube.h)

add_custom_command(TARGET RCube POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/RCube/Cubein.txt
        $<TARGET_FILE_DIR:RCube>/Cubein.txt)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(RCube PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT)

add_executable(RCube-tests
        RCubeTests/test_cube.cpp
        RCube/cube_realization.cpp
        RCube/rotations.cpp
        RCube/solver.cpp
        RCube/visual_cube.cpp
        RCubeTests/MockCube.h)

find_package(GTest REQUIRED)

include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

target_link_libraries(RCube-tests doctest)
target_link_libraries(RCube-tests OpenGL::GL OpenGL::GLU GLUT::GLUT)
target_link_libraries(RCube-tests gmock gtest pthread)

enable_testing()
add_test(NAME RCube-tests COMMAND RCube-tests --force-colors -d)
