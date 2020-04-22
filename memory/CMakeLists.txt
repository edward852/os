cmake_minimum_required(VERSION 3.15)
project(memory)

set(CMAKE_CXX_STANDARD 11)
add_executable(memory main.cpp)

# gdb或valgrind
#set(CMAKE_CXX_FLAGS "-g -fno-omit-frame-pointer")

# 动态链接asan库
set(CMAKE_CXX_FLAGS "-g -fsanitize=address -fno-omit-frame-pointer")
#target_link_libraries(memory -lasan)

# 静态链接asan库
#set(CMAKE_CXX_FLAGS "-g -fsanitize=address -fno-omit-frame-pointer -static-libasan")

