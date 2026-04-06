//
// Created by User on 5/04/2026.
//

#include "Funciones.hpp"

void apertura_Archivo_entradA(ifstream&input,const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout<<"Archivo no encontrado: "<<file_name<<endl;
        exit(1);
    }
}
void apertura_Archivo_Salida(ofstream& output,const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout<<"Archivo no encontrado: "<<file_name<<endl;
        exit(1);
    }
}