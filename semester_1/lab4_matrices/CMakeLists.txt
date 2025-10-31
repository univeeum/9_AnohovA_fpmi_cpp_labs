cmake_minimum_required(VERSION 3.10)
project(lab4)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*,-readability-magic-numbers")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task task.cpp)
add_executable(main main.cpp)