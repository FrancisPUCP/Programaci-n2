cmake_minimum_required(VERSION 4.2)
project(Fuentes_Biblioteca_2023_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuentes_Biblioteca_2023_2 main.cpp
        Bibliotecas/SobreCarga.cpp
        Bibliotecas/SobreCarga.hpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.hpp)
