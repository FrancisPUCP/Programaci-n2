//
// Created by User on 5/04/2026.
//

#include "Funciones.hpp"
void   emitir_reporte(struct Libro *arrLibros, struct Cliente *arrClientes, int numero_clientes) {
    ofstream output;apertura_Archivos_salida(output,"ClientesyLibrosActualizados.csv");
    output<<setw(80)<<"DATOS DE LOS CLIENTES"<<endl;
    for (int i=0; i<numero_clientes; i++) {
        output<<arrClientes[i];
    }
    output<<setw(80)<<right<<"DATOS DE LOS LIBROS"<<endl;
    for (int i=0; strcmp(arrLibros[i].codigo,"FIN")!=0; i++) {
        output<<arrLibros[i];
    }
}
void completar_datos (struct Libro *arrLibros, struct Cliente *arrClientes, int numero_clientes) {
    ifstream input;apertura_Archivos_entrada(input,"Pedidos.txt");
    struct LibroSolicitado pedido;
    int dni;
    while (true) {
        input>>pedido.numeroDePedido;input.get();
        if (input.eof()) break;
        input>>dni;input.get();
        while (true) {
            input>>pedido.codigoDelLibro;
            // modificar
            pedido>>arrLibros;
            for (int i=0; i<numero_clientes; i++) {
                if (arrClientes[i].dni==dni) {
                    arrClientes[i]<<pedido;
                    break;
                }
            }
            if (input.peek()=='\n') break;
        }
    }
    actualizarPagosClientes(arrClientes, numero_clientes);
}
void     leer_clientes(struct Cliente *arrClientes,int &numero_clientes) {
    ifstream input;apertura_Archivos_entrada(input,"Cientes.csv");
    while (input>>arrClientes[numero_clientes]) {
        numero_clientes++;
    }
}
void     leer_libros(struct Libro *arrLibros) {
    ifstream input;apertura_Archivos_entrada(input,"Libros.csv");
    int i=0;
    while (input>>arrLibros[i]) {
        i++;
    }
    strcpy(arrLibros[i].codigo,"FIN");
}
void apertura_Archivos_salida(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error al abrir el archivo de salida: " << file_name << endl;
        exit(1);
    }
}

void apertura_Archivos_entrada(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo de entrada: " << file_name << endl;
        exit(1);
    }
}
