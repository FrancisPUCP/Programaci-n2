#include <iostream>
#include "Bibliotecas/Funciones.hpp"
#include "Bibliotecas/SobreCarga.hpp"
int main() {
    struct Libro arrLibros[300];
    leer_libros(arrLibros);
    int numero_clientes=0;
    struct Cliente arrClientes[300];
    leer_clientes(arrClientes, numero_clientes);
    completar_datos(arrLibros, arrClientes, numero_clientes);
    emitir_reporte(arrLibros, arrClientes, numero_clientes);
    return 0;
}
