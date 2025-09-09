cmake_minimum_required(VERSION 3.10)
project(tasks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task1 task1.cpp)
add_executable(task3 task3.cpp)
add_executable(task4 task4.cpp)
add_executable(task7 task7.cpp)
add_executable(task11 task11.cpp)
add_executable(task12 task12.cpp)
add_executable(task13 task13.cpp)

add_custom_target(all_tasks DEPENDS task1 task3 task4 task7 task11 task12 task13)