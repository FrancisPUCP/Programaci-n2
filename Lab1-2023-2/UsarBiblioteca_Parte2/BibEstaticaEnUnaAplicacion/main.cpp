#include <iostream>
#include "Bibliotecas/Funciones.hpp"
#include "Bibliotecas/SobreCarga.hpp"
int main() {
    struct Cliente clientes[200];
    ifstream input;apertura_Archivo_entradA(input,"Clientes.csv");
    leer_clientes(input,clientes);
    struct Producto productos[200];
    ifstream input2;apertura_Archivo_entradA(input2,"Productos.csv");
    leer_productos(input2,productos);
    cargar_datos(clientes,productos);
    ofstream output;apertura_Archivo_Salida(output,"Reporte.txt");
    emitir_reporte(output,clientes,productos);
    return 0;
}
