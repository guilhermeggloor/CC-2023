cmake_minimum_required(VERSION 3.25)
project(arvorebinaria C)

set(CMAKE_C_STANDARD 11)

include_directories(gfx)

add_executable(arvorebinaria
        gfx/gfx.c
        gfx/gfx.h
        arvbin.c)
