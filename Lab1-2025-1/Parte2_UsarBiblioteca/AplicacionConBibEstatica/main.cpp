#include <iostream>

#include "Bibliotecas/Funciones.hpp"
#include "Bibliotecas/SobreCargas.hpp"
int main() {
    int dni[200];
    struct CadenaDeCaracteres conductor[200], placa[200];
    int cant_conductores=0;
    ifstream input;apertura_Archivo_entrada(input, "Infracciones de transito.txt");
    cargar_datos(input,dni,conductor,placa,cant_conductores);
    ordenar_Datos(dni,conductor,placa,cant_conductores);
    ofstream output; apertura_Archivo_salida(output, "Reporte.txt");
    imprimir_reporte(output,dni,conductor,placa,cant_conductores);
    return 0;
}
