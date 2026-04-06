//
// Created by User on 5/04/2026.
//

#include "SobreCarga.hpp"
bool operator >> (ifstream &input, struct Libro &libro) {
    input.getline(libro.codigo, 8, ',');
    if (input.eof()) return false;
    input.getline(libro.tiltulo, 80, ',');
    input.getline(libro.autor, 60, ',');
    input >> libro.stock;input.get();
    input>>libro.precio;input.get();
    return true;
}
bool operator >>(ifstream &input,struct Cliente &cliente) {
    input>>cliente.dni;input.get();
    if (input.eof()) return false;
    input.getline(cliente.nombre, 60, '\n');
    cliente.cantDeLibros=0;
    cliente.pagoTotal=0;
    return true;
}
bool operator >> (struct LibroSolicitado &libroPedido, struct Libro *arregloLibros) {
    int numero_libro = -1;
    for (int i=0; strcmp(arregloLibros[i].codigo,"FIN")!=0; i++) {
        if (strcmp(libroPedido.codigoDelLibro,arregloLibros[i].codigo)==0) {
            numero_libro=i;
            break;
        }
    }

    if (numero_libro == -1) {
        libroPedido.atendido=false;
        libroPedido.precio=0;
        return false;
    }

    if (arregloLibros[numero_libro].stock>0) {
        libroPedido.precio=arregloLibros[numero_libro].precio;
        arregloLibros[numero_libro].stock--;
        libroPedido.atendido=true;
        return true;
    } else {
        libroPedido.atendido=false;
        libroPedido.precio=0;
        return false;
    }
}
bool operator << (struct Cliente &cliente, struct LibroSolicitado &pedido) {
    if (cliente.cantDeLibros<30) {
        cliente.librosSolicitados[cliente.cantDeLibros]=pedido;
        cliente.cantDeLibros++;
        return true;
    } else {
        return false;
    }
}
void operator ++(struct Cliente &cliente) {
    cliente.pagoTotal = 0; // idempotente
    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (cliente.librosSolicitados[i].atendido==true) {
            cliente.pagoTotal+=cliente.librosSolicitados[i].precio;
        }
    }
}

void actualizarPagosClientes(struct Cliente *arregloClientes, int cantClientes) {
    for (int i = 0; i < cantClientes; i++) {
        ++arregloClientes[i];
    }
}
ofstream& operator << (ofstream &output,struct Libro &libro){
    output<<libro.codigo<<"  "
    <<setw(80)<<left<<libro.tiltulo<<"  "
    <<setw(60)<<libro.autor<<"  "
    <<setw(4)<<right<<libro.stock<<"  "
    <<setw(5)<<fixed<<setprecision(2)<<libro.precio<<endl;
    return output;
}
ofstream& operator << (ofstream &output,struct Cliente &cliente){
    output<<cliente.dni<<"  "
    <<setw(60)<<left<<cliente.nombre<<endl;

    output<<"Libros entregados:"<<endl
    <<setw(10)<<" "<<left<<setw(15)<<"Pedido No."<<"  "
    <<setw(10)<<"Codigo"<<right<<setw(10)<<"Precio"<<endl;

    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (cliente.librosSolicitados[i].atendido==true) {
            output<<setw(10)<<""; // margen izquierdo
            output<<setfill('0')<<setw(6)<<right<<cliente.librosSolicitados[i].numeroDePedido;
            output<<setfill(' ')<<"          "
                  <<left<<setw(10)<<cliente.librosSolicitados[i].codigoDelLibro
                  <<right<<setw(10)<<fixed<<setprecision(2)<<cliente.librosSolicitados[i].precio
                  <<endl;
        }
    }

    output<<"Total a pagar: "<<fixed<<setprecision(2)<<cliente.pagoTotal<<endl;
    output<<"Libros no entregados por falta de stock:"<<endl
    <<setw(10)<<left<<" "<<setw(15)<<"Pedido No."<<"  "
    <<setw(10)<<"Codigo"<<endl;

    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (cliente.librosSolicitados[i].atendido==false) {
            output<<setw(10)<<""; // margen izquierdo
            output<<setfill('0')<<setw(6)<<right<<cliente.librosSolicitados[i].numeroDePedido;
            output<<setfill(' ')<<"  "
                  <<left<<setw(10)<<cliente.librosSolicitados[i].codigoDelLibro
                  <<endl;
        }
    }

    return output;
}
