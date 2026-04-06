//
// Created by User on 5/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2024_1_FUNCIONES_HPP
#define FUENTES_BIBLIOTECA_2024_1_FUNCIONES_HPP
#include "Utils.hpp"
#include "SobreCarga.hpp"
void   emitir_reporte(struct Libro *arrLibros, struct Cliente *arrClientes, int numero_clientes);
void completar_datos (struct Libro *arrLibros, struct Cliente *arrClientes, int numero_clientes);
void     leer_clientes(struct Cliente *arrClientes,int &numero_clientes);
void     leer_libros(struct Libro *arrLibros);
void apertura_Archivos_entrada(ifstream &input, const char*file_name);
void apertura_Archivos_salida(ofstream &output, const char*file_name);

#endif //FUENTES_BIBLIOTECA_2024_1_FUNCIONES_HPP
