cmake_minimum_required(VERSION 3.10)
project(profiling)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -fno-omit-frame-pointer")
#set(CMAKE_CXX_FLAGS "-g")

add_executable(profiling main.cpp)