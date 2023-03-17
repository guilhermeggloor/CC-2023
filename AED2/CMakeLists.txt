cmake_minimum_required(VERSION 3.24)
project(AED2 C)

set(CMAKE_C_STANDARD 11)

include_directories(recursivo)

add_executable(AED2
        recursivo/palindromo.c
        recursivo/soma.c)
