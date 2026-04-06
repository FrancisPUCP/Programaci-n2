cmake_minimum_required(VERSION 4.2)
project(Biblioteca_2025_1_Fuentes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Biblioteca_2025_1_Fuentes main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/SobreCargas.cpp
        Bibliotecas/SobreCargas.hpp
        Bibliotecas/Struct.hpp
)
