//
// Created by User on 4/04/2026.
//

#include "SobreCargas.hpp"
void operator ! (struct CadenaDeCaracteres &cadena) {
    cadena.cadena=nullptr;
    cadena.capacidad=0;
    cadena.longitud=0;
}
void operator <= (struct CadenaDeCaracteres &cadena, const char *cad) {
    if (cadena.cadena==nullptr or cadena.capacidad<strlen(cad)+1) {
        cadena.capacidad=strlen(cad)+1;
        if (cadena.cadena != nullptr) delete cadena.cadena;
        cadena.cadena=new char[cadena.capacidad]{};
    }
    strcpy(cadena.cadena, cad);
    cadena.longitud=strlen(cad);
}
void operator <=(struct CadenaDeCaracteres &cadena, int espacio_memoria) {
    delete [] cadena.cadena;
    cadena.cadena= new char[espacio_memoria]{};
    cadena.capacidad=espacio_memoria;
    cadena.longitud=0;
}
void operator <= (struct CadenaDeCaracteres &cadena1, struct CadenaDeCaracteres &cadena2) {
    cadena1<=cadena2.cadena;
}
bool operator += (struct CadenaDeCaracteres &cadena,const char *cad) {
    char *buffer;
    if (cadena.cadena ==nullptr or cadena.longitud==0) return false;
    if (cadena.capacidad<(cadena.longitud+strlen(cad) +1)) {
        cadena.capacidad=cadena.longitud+strlen(cad) +1;
        buffer= new char [cadena.capacidad];
        strcpy(buffer, cadena.cadena);
        strcat(buffer, cad);
        delete cadena.cadena;
        cadena.cadena=buffer;
    }else {
        strcat(cadena.cadena, cad);
    }
    cadena.longitud+=strlen(cad);
    return true;
}
bool operator += (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2) {
    return cadena1+=cadena2.cadena;
}
int compare (struct CadenaDeCaracteres &cadena,const char *cad) {
    char buffer1[cadena.capacidad],buffer2[strlen(cad)+1];
    strcpy(buffer1, cadena.cadena);
    strcpy(buffer2, cad);
    for (int i=0;buffer1[i];i++) {
        if (buffer1[i]>='A' and buffer1[i]<='Z') buffer1[i]=buffer1[i]+32;
    }
    for (int i=0;buffer2[i];i++) {
        if (buffer2[i]>='A' and buffer2[i]<='Z') buffer2[i]=buffer2[i]+32;
    }
    return strcmp(buffer1, buffer2); // recordemos si son iguales returnan 0, si buffer 1 es mayor que buffer 2 retorna un >0 y sino un <0
}
bool operator == (struct CadenaDeCaracteres &cadena,const char *cad) {
    return compare(cadena,cad)==0;
}
bool operator > (struct CadenaDeCaracteres &cadena,const char *cad) {
    return compare(cadena,cad)>0;
}
bool operator < (struct CadenaDeCaracteres &cadena,const char *cad) {
    return compare(cadena,cad)<0;
}
int compare (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2) {
    return compare (cadena1,cadena2.cadena);
}
bool operator == (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2) {
    return compare(cadena1,cadena2)==0;
}
bool operator > (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2) {
    return (compare(cadena1,cadena2)>0);
}
bool operator < (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2) {
    return (compare(cadena1,cadena2)<0);
}
int operator >> (ifstream &input,struct CadenaDeCaracteres &cadena) {
    char buffer[100];
    input>>buffer;
    if (input.eof()) return 1;
    if (not ((buffer[0]>='A' && buffer[0]<='Z') or (buffer[0]>='a' && buffer[0]<='z'))) return -1;
    cadena<=buffer;
    return 0;
}
void operator && (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2) {
    struct CadenaDeCaracteres aux;
    aux=cadena1;
    cadena1=cadena2;
    cadena2=aux;
}
ofstream& operator << (ofstream &output,struct CadenaDeCaracteres &cadena) {
    output<<cadena.cadena;
    return output;
}

