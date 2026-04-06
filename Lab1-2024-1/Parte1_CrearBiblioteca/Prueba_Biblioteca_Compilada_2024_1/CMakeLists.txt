cmake_minimum_required(VERSION 4.2)
project(Prueba_Biblioteca_Compilada_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prueba_Biblioteca_Compilada_2024_1 main.cpp
        Bibliotecas/Funciones.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/Bibliotecas")

target_link_libraries(Prueba_Biblioteca_Compilada_2024_1 PRIVATE SobreCarga)
