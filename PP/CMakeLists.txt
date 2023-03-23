cmake_minimum_required(VERSION 3.22)
project(PP)

set(CMAKE_CXX_STANDARD 14)

add_executable(PP
        "Classes_Objetos/Circulo/ main.cpp"
        Classes_Objetos/Circunferencia/main.cpp
        Classes_Objetos/Exemplo/main.cpp
        Classes_Objetos/pontos/main.cpp)
