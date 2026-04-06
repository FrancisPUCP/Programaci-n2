//
// Created by User on 5/04/2026.
//

#include "Funciones.hpp"
void emitir_reporte(ofstream &output,struct Cliente *clientes,struct Producto *productos) {
    // productos
    output<<setw(80)<<"DATOS DE LOS PRODUCTOS"<<endl;
    for (int i=0;strcmp(productos[i].codigo,"XXXXXXX")!=0;i++) {
        output<<productos[i];
    }
    output<<setw(80)<<"DATOS DE LOS CLIENTES"<<endl;
    for (int i=0;clientes[i].dni!=0;i++) {
        output<<clientes[i];
    }
}
void     cargar_datos(struct Cliente *clientes,struct Producto *productos) {
    ifstream input;apertura_Archivo_entradA(input,"Pedidos.csv");
    struct Pedido pedido;
    while (input>>pedido) {
        productos+=pedido;
        clientes+=pedido;
    }
}
void   leer_productos(ifstream &input2,struct Producto *productos) {
    int i=0;
    while (input2>>productos[i]) i++;
    strcpy(productos[i].codigo,"XXXXXXX");
}
void  leer_clientes(ifstream &input,struct Cliente *clientes) {
    int i=0;
    while (input>>clientes[i]) i++;
    clientes[i].dni=0;
}
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