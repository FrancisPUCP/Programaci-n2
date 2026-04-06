//
// Created by User on 4/04/2026.
//

#ifndef APLICACIONCONBIBESTATICA_FUNCIONES_HPP
#define APLICACIONCONBIBESTATICA_FUNCIONES_HPP
#include "Utils.hpp"
#include "SobreCargas.hpp"
void  imprimir_reporte(ofstream &output,int *dni,struct CadenaDeCaracteres *conductor,struct CadenaDeCaracteres *placa,int cant_conductores);
void imprimir_linea(ofstream &output,int len, char a);
void ArreglarNombre(char *cadena);
void ordenar_Datos(int *dni,struct CadenaDeCaracteres *conductor,struct CadenaDeCaracteres *placa,int cant_conductores);
void cargar_datos(ifstream &input,int *dni,struct CadenaDeCaracteres *conductor,struct CadenaDeCaracteres *placa,int &cant_conductores);
void apertura_Archivo_entrada(ifstream &input, const char*file_name);
void apertura_Archivo_salida(ofstream &output, const char*file_name);
#endif //APLICACIONCONBIBESTATICA_FUNCIONES_HPP
