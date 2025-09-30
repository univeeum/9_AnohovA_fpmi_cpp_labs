cmake_minimum_required(VERSION 3.10)
project(lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3_dynamic lab3_dynamic.cpp)
add_executable(lab3_static lab3_static.cpp)

add_custom_target(tasks DEPENDS lab3_static lab3_dynamic)