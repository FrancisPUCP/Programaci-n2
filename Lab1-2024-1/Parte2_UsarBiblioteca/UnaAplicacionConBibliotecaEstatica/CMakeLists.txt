cmake_minimum_required(VERSION 4.2)
project(UnaAplicacionConBibliotecaEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UnaAplicacionConBibliotecaEstatica main.cpp
        Bibliotecas/Funciones.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/Bibliotecas")

target_link_libraries(UnaAplicacionConBibliotecaEstatica PRIVATE SobreCarga)
