cmake_minimum_required(VERSION 3.25)
project(W2 C)

set(CMAKE_C_STANDARD 11)

include_directories(gfx)

add_executable(W2
        gfx/gfx.c
        gfx/gfx.h
        aloc_encadeada.c)
