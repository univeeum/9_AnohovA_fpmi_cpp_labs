cmake_minimum_required(VERSION 3.10)
project(lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task3 task3.cpp)
add_executable(dop_task1 dop_task1.cpp)
add_executable(dop_task2 dop_task2.cpp)

add_custom_target(tasks DEPENDS task3 dop_task1 dop_task2)