cmake_minimum_required(VERSION 3.24)
project(opengl_example)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        opengl_example
        main.cpp
        #        KHR/khrplatform.h
        glad.c
        implementation.cpp
        implementation.h
        bitscreen.cpp bitscreen.h)

target_link_libraries(opengl_example GL dl glfw)

