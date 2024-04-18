cmake_minimum_required(VERSION 3.21)
project(BFS C)

set(CMAKE_C_STANDARD 99)

add_executable(BFS main.c BFS_lib.c BFS_head.h)
