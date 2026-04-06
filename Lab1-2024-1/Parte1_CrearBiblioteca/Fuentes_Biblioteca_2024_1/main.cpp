#include <iostream>
#include <cstring>
#include "Bibliotecas/SobreCarga.hpp"
#include "Bibliotecas/Funciones.hpp"

int main() {
    ifstream input;apertura_Archivos_entrada(input,"Libros.csv");
    struct Libro arregloLibros[300];
    int i=0;
    while (input>>arregloLibros[i]) i++;
    strcpy(arregloLibros[i].codigo,"FIN");
    ifstream input2;apertura_Archivos_entrada(input2,"Cientes.csv");
    struct Cliente arregloClientes[100];
    int j=0;
    while (input2>>arregloClientes[j]) j++;
    ifstream input3;apertura_Archivos_entrada(input3,"Pedidos.txt");
    struct LibroSolicitado libroPedido;
    int dni;
    while (true) {
        input3>>libroPedido.numeroDePedido;input3.get();
        if (input3.eof()) break;
        input3>>dni;input3.get();
        while (true) {
            input3>>libroPedido.codigoDelLibro;
            // modificar
            libroPedido>>arregloLibros;
             for (int k=0;k<j;k++) {
                 if (arregloClientes[k].dni==dni) {
                     arregloClientes[k]<<libroPedido;
                     break;
                 }
             }
            if (input3.peek()=='\n') break;
        }
    }
    actualizarPagosClientes(arregloClientes, j);

        ofstream output;apertura_Archivos_salida(output,"ClientesActualizados.csv");
        for (int k=0;k<j;k++) {
            output<<arregloClientes[k];
        }
        ofstream output2;apertura_Archivos_salida(output2,"LibrosActualizados.csv");
        for (int k=0; strcmp(arregloLibros[k].codigo,"FIN")!=0; k++) {
            output2<<arregloLibros[k];
        }
    return 0;
}
