cmake_minimum_required(VERSION 3.10)
project(deadlock)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -fno-omit-frame-pointer")

add_executable(deadlock main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(deadlock ${CMAKE_THREAD_LIBS_INIT})
