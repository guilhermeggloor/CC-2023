cmake_minimum_required(VERSION 3.25)
project(aulas C)

set(CMAKE_C_STANDARD 11)

add_executable(aulas
        "alocação encadeada/lista.c"
        arvore/len.c
        "lista/remover lista/lista.c"
        lista/len.c
        recursivo/palindromo.c
        recursivo/soma.c)
