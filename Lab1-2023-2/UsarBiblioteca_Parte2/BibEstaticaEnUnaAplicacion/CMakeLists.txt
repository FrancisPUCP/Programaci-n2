cmake_minimum_required(VERSION 4.2)
project(BibEstaticaEnUnaAplicacion)

set(CMAKE_CXX_STANDARD 20)

add_executable(BibEstaticaEnUnaAplicacion main.cpp
        Bibliotecas/Funciones.cpp)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(BibEstaticaEnUnaAplicacion PRIVATE SobreCarga)
