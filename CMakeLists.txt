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

# Найти pybind11
find_package(/myenv/lib/python3.11/site-packages/ppybind11 REQUIRED)

# Найти Python из виртуальной среды
set(Python3_EXECUTABLE ${CMAKE_SOURCE_DIR}/myenv/bin/python)
set(Python3_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/myenv/include/python3.11)
set(Python3_LIBRARIES ${CMAKE_SOURCE_DIR}/myenv/lib)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Подключить библиотеки Python
target_link_libraries(RCube PRIVATE pybind11::embed Python3::Python)

# Установить флаги компилятора для Python
target_include_directories(RCube PRIVATE ${Python3_INCLUDE_DIRS})
target_link_libraries(RCube PRIVATE ${Python3_LIBRARIES})

# Установить переменную окружения PYTHONPATH, чтобы указать на site-packages вашей виртуальной среды
set(ENV{PYTHONPATH} ${Python3_LIBRARIES}/python3.11/site-packages)
