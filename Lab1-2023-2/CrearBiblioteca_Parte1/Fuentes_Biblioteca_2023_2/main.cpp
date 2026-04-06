#include <iostream>

#include "Bibliotecas/Funciones.hpp"
#include "Bibliotecas/SobreCarga.hpp"

int main() {
    ifstream input; apertura_Archivo_entradA(input,"Clientes.csv");
    struct Cliente clientes[200];
    int i=0;
    while (input>>clientes[i]) {
        i++;
    }
    clientes[i].dni=0;
    ifstream input2;apertura_Archivo_entradA(input2,"Productos.csv");
    struct Producto productos[200];
    int j=0;
    while (input2>>productos[j]) {
        j++;
    }
    strcpy(productos[i].codigo,"XXXXXXX");

    ifstream input3;apertura_Archivo_entradA(input3,"Pedidos.csv");
    struct Pedido pedidos[1000];
    i=0;
    while (input3>>pedidos[i]) {
        i++;
    }
    int cantidad_pedidos=i-1;

    for (int j=0;j<cantidad_pedidos;j++) {
        productos+=pedidos[j];
    }
    for (int j=0;j<cantidad_pedidos;j++) {
        clientes+=pedidos[j];
    }

    ofstream output;apertura_Archivo_Salida(output,"REPORTE.TXT");
    for (int j=0;clientes[j].dni!=0;j++) {
        output<<clientes[j];
    }
    for (int j=0;strcmp(productos[j].codigo,"XXXXXXX")!=0;j++) {
        output<<productos[j];
    }
    return 0;
}
