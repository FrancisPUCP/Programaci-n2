//
// Created by User on 5/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2023_2_SOBRECARGA_HPP
#define FUENTES_BIBLIOTECA_2023_2_SOBRECARGA_HPP
#include "Estructuras.h"
#include "Utils.hpp"
void emitir_reporte(ofstream &output,struct Cliente *clientes,struct Producto *productos);
void     cargar_datos(struct Cliente *clientes,struct Producto *productos);
void   leer_productos(ifstream &input2,struct Producto *productos);
bool operator >>(ifstream &input,struct Cliente &cliente);
bool operator >> (ifstream &input,struct Producto &producto);
bool operator >> (ifstream &input, struct Pedido &pedido);
void operator += (struct Cliente *arrClientes, struct Pedido &pedido);
bool operator += (struct Producto *arrProductos, struct Pedido &pedido);
ofstream& operator << (ofstream &output, struct Cliente &cliente);
ofstream &operator << (ofstream &output, struct Producto &producto);
#endif //FUENTES_BIBLIOTECA_2023_2_SOBRECARGA_HPP
