//
// Created by User on 5/04/2026.
//

#include "SobreCarga.hpp"

bool operator >>(ifstream &input,struct Cliente &cliente) {
    input>>cliente.dni;input.get();
    if (input.eof()) return false;
    input.getline(cliente.nombre,60,',');
    input>>cliente.telefono;
    cliente.cantidadProductosEntrgados=0;
    cliente.montoTotal=0;
    return true;
}
bool operator >> (ifstream &input,struct Producto &producto) {
    input.getline(producto.codigo,8,',');
    if (input.eof()) return false;
    input.getline(producto.descripcion,60,',');
    input>>producto.precio;input.get();
    input>>producto.stock;input.get();
    producto.cantidadClientesNoServidos=0;
    producto.cantidadClientesServidos=0;
    return true;
}
bool operator >> (ifstream &input, struct Pedido &pedido) {
    input.getline(pedido.CodigoProducto,8,',');
    if (input.eof()) return false;
    input>>pedido.dniCliente;input.get();
    pedido.precioProducto=0;
    return true;
}
void operator += (struct Cliente *arrClientes, struct Pedido &pedido) {
    int numero_cliente;
    for (int i=0;arrClientes[i].dni!=0;i++) {
        if (pedido.dniCliente==arrClientes[i].dni) {
            numero_cliente=i;
        }
    }
    int numero_producto=arrClientes[numero_cliente].cantidadProductosEntrgados;
    arrClientes[numero_cliente].productosEntregados[numero_producto].precio=pedido.precioProducto;
    strcpy(arrClientes[numero_cliente].productosEntregados[numero_producto].codigo,pedido.CodigoProducto);
    arrClientes[numero_cliente].cantidadProductosEntrgados++;
    arrClientes[numero_cliente].montoTotal+=pedido.precioProducto;
}
bool operator += (struct Producto *arrProductos, struct Pedido &pedido){
    int numero_producto;
    for (int i=0;strcmp(arrProductos[i].codigo,"XXXXXXX")!=0;i++) {
        if (strcmp(pedido.CodigoProducto,arrProductos[i].codigo)==0) {
            numero_producto=i;
        }
    }
    int numero_cliente;
    pedido.precioProducto=arrProductos[numero_producto].precio;
    if (arrProductos[numero_producto].stock>0) {
        numero_cliente=arrProductos[numero_producto].cantidadClientesServidos;
        arrProductos[numero_producto].clientesServidos[numero_cliente]=pedido.dniCliente;
        arrProductos[numero_producto].cantidadClientesServidos++;
    }else {
        numero_cliente=arrProductos[numero_producto].cantidadClientesNoServidos;
        arrProductos[numero_producto].clientesNoServidos[numero_cliente]=pedido.dniCliente;
        arrProductos[numero_producto].cantidadClientesNoServidos++;
    }
    if (arrProductos[numero_producto].stock>0) {
        arrProductos[numero_producto].stock--;
        return true;
    }else {
        return false;
    }
}
ofstream& operator << (ofstream &output, struct Cliente &cliente){
    output<<cliente.dni<<" "
    <<setw(60)<<left<<cliente.nombre
    <<setw(10)<<cliente.telefono<<"  "
    <<fixed<<setprecision(2)<<setw(10)<<right<<cliente.montoTotal<<"  "
    <<setw(20)<<"Productos Entregados: ";
    if (cliente.cantidadProductosEntrgados>0) {
        for (int i=0;i<cliente.cantidadProductosEntrgados;i++) {
            output<<cliente.productosEntregados[i].codigo<<" ";
        }
    }else {
        output<<"NO SE LE ENTREGARON PRODUCTOS";
    }
    output<<endl;
    return output;
}
ofstream &operator << (ofstream &output, struct Producto &producto) {
    output<<producto.codigo<<" "
    <<setw(60)<<left<<producto.descripcion
    <<setw(10)<<fixed<<setprecision(2)<<producto.precio
    <<producto.stock<<right<<endl
    <<"Clientes atendidos: ";
    if (producto.cantidadClientesServidos>0) {
        for (int i=0;i<producto.cantidadClientesServidos;i++) {
            output<<producto.clientesServidos[i]<<" ";
        }
        output<<endl;
    }else {
        output<<"NO SE ATENDIERON PEDIDO"<<endl;
    }
    output<<"Clientes no atendidos: ";
    if (producto.cantidadClientesNoServidos>0) {
        for (int i=0;i<producto.cantidadClientesNoServidos;i++) {
            output<<producto.clientesNoServidos[i]<<" ";
        }
        output<<endl;
    }else {
        output<<"NO HAY CLIENTES SIN ATENDER"<<endl;
    }
    return output;
}

