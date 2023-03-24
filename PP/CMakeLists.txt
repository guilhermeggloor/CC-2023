cmake_minimum_required(VERSION 3.22)
project(PP)

set(CMAKE_CXX_STANDARD 14)

add_executable(PP
        "Classes_Objetos/Circulo/circle.cpp"
        Classes_Objetos/Circunferencia/circunference.cpp
        Classes_Objetos/Exemplo/main.cpp
        Classes_Objetos/pontos/pointers.cpp Classes_Objetos/Destrutor/descructor_node.cpp)

