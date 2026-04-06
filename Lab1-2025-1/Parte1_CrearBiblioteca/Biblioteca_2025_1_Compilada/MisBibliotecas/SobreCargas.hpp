//
// Created by User on 4/04/2026.
//

#ifndef BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
#define BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
#include "Utils.hpp"
#include "Struct.hpp"
void operator ! (struct CadenaDeCaracteres &cadena);
void operator <= (struct CadenaDeCaracteres &cadena, const char *cad);
void operator <=(struct CadenaDeCaracteres &cadena, int espacio_memoria);
void operator <= (struct CadenaDeCaracteres &cadena1, struct CadenaDeCaracteres &cadena2);
bool operator += (struct CadenaDeCaracteres &cadena,const char *cad);
bool operator += (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2);
int compare (struct CadenaDeCaracteres &cadena,const char *cad);
bool operator == (struct CadenaDeCaracteres &cadena,const char *cad);
bool operator > (struct CadenaDeCaracteres &cadena,const char *cad);
bool operator < (struct CadenaDeCaracteres &cadena,const char *cad);
int compare (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2);
bool operator == (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2);
bool operator > (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2);
bool operator < (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2);
int operator >> (ifstream &input,struct CadenaDeCaracteres &cadena);
void operator && (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2);
ofstream& operator << (ofstream &output,struct CadenaDeCaracteres &cadena);
#endif //BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
