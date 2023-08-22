cmake_minimum_required(VERSION 3.22)
project(Works C)

set(CMAKE_C_STANDARD 11)

include_directories(W1/gfx)

add_executable(Works
        W1/gfx/gfx.c
        W1/gfx/gfx.h
        W1/circle_square.c
        W4/AVL.h
        W4/AVL.c)
