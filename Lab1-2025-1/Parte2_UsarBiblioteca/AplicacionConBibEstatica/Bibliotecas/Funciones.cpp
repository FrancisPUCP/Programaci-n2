//
// Created by User on 4/04/2026.
//

#include "Funciones.hpp"

#include "Struct.hpp"
void  imprimir_reporte(ofstream &output,int *dni,struct CadenaDeCaracteres *conductor,struct CadenaDeCaracteres *placa,int cant_conductores) {
    output<<setw((MAXIMO-TITULO)/2)<<"REPORTE DE INFRACTORES DE TRANSITO"<<endl;
    imprimir_linea(output,100,'=');
    output<<setw(5)<<"DNI"<<setw(15)<<"INFRACTOR"<<setw(25)<<"PLACA"<<endl;
    imprimir_linea(output,100,'-');
    for (int i=0;i<cant_conductores-1;i++) {
        output<<setw(10)<<dni[i]<<"  "<<left<<setw(60);
        ArreglarNombre(conductor[i].cadena);
        output<<conductor[i];
        output<<"  "<<setw(9);
        output<<placa[i];
        output<<endl<<right;

    }
}
void imprimir_linea(ofstream &output,int len, char a) {
    for (int i=0;i<len;i++) {
        output<<a;
    }
    output<<endl;
}
void ArreglarNombre(char *cadena) {
    for (int i=0; cadena[i]; i++) {
        if (i==0 or cadena[i-1]=='_') {
            if (cadena[i]>='a' && cadena[i]<='z') cadena[i]=cadena[i]-32;
        }else {
            if (cadena[i]>='A' && cadena[i]<='Z') cadena[i]+=32;
        }
    }
}
void ordenar_Datos(int *dni,struct CadenaDeCaracteres *conductor,struct CadenaDeCaracteres *placa,int cant_conductores) {
    for (int i=0;i<cant_conductores-1;i++) {
        for (int j=0;j<cant_conductores-i-1;j++) {
            if ((conductor[j]<conductor[j+1])==true) {
                conductor[j]&&conductor[j+1];
                placa[j]&&placa[j+1];
                int dni_aux= dni[j];
                dni[j]= dni[j+1];
                dni[j+1]= dni_aux;
            }
        }

    }
}
void cargar_datos(ifstream &input,int *dni,struct CadenaDeCaracteres *conductor,struct CadenaDeCaracteres *placa,int &cant_conductores) {
    struct CadenaDeCaracteres buffer;
    while (true) {
        !conductor[cant_conductores];
        !placa[cant_conductores];
        input>>dni[cant_conductores];
        if(input.eof()) break;
        int i=0;
        !buffer;
        while ((input>>buffer)==0) {
            if (i==0) conductor[cant_conductores]<=buffer;
            else {
                conductor[cant_conductores]+="_";
                conductor[cant_conductores]+=buffer;
            }
            i++;
        }
        input>>placa[cant_conductores];
        cant_conductores++;
    }
}

void apertura_Archivo_entrada(ifstream &input, const char*file_name) {
    input.open(file_name, ios::in);
    if(!input.is_open()) {
        cout<<"Archivo no encontrado"<<file_name<<endl;
    }
}
void apertura_Archivo_salida(ofstream &output, const char*file_name) {
    output.open(file_name, ios::out);
    if(!output.is_open()) {
        cout<<"Archivo no encontrado"<<file_name<<endl;
    }
}