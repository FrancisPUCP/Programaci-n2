//
// Created by User on 5/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2024_1_SOBRECARGA_HPP
#define FUENTES_BIBLIOTECA_2024_1_SOBRECARGA_HPP
#include "Utils.hpp"
#include "Estructuras.h"
bool operator >> (ifstream &input, struct Libro &libro);
bool operator >>(ifstream &input,struct Cliente &cliente);
bool operator >> (struct LibroSolicitado &libroPedido, struct Libro *arregloLibros);
bool operator << (struct Cliente &cliente, struct LibroSolicitado &pedido);
void operator ++(struct Cliente &cliente);
void actualizarPagosClientes(struct Cliente *arregloClientes, int cantClientes);
ofstream& operator << (ofstream &output,struct Libro &libro);
ofstream& operator << (ofstream &output,struct Cliente &cliente);


#endif //FUENTES_BIBLIOTECA_2024_1_SOBRECARGA_HPP
