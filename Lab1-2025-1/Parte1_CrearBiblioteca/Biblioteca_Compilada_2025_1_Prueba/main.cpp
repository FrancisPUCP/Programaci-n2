#include <iostream>

#include "Bibliotecas/SobreCargas.hpp"
int main() {
    struct CadenaDeCaracteres cadena1;
    !cadena1;
    cout<<setw(2)<<cadena1.capacidad<<setw(2)<<cadena1.longitud<<setw(2)<<endl;
    char cadena2 []= "Programacion2";
    cadena1<=cadena2;
    cout<<cadena1.cadena<<endl;
    struct CadenaDeCaracteres cadena3;
    !cadena3;
    cadena3<=10;
    cout<<"Espacio de cadena 3: "<<cadena3.capacidad<<endl;
    cadena3<=cadena1;
    cout<<cadena3.cadena<<endl;

    cadena3+="_";
    cadena3+=cadena1;
    cout<<cadena3.cadena<<endl;
    bool comparacion;
    comparacion= cadena1==cadena2;
    cout<<comparacion<<endl;
    comparacion= cadena3>cadena1;
    cout<<comparacion<<endl;
    ifstream input;
    int dni;
    struct CadenaDeCaracteres cadena; !cadena;
    input.open("Infracciones de transito.txt",ios::in);
    input>>dni;
    input>>cadena;
    ofstream output;
    output.open("Cadena de transito.txt",ios::out);
    output<<cadena<<cadena2;
    cadena && cadena1;
    output<<cadena<<cadena1;

    return 0;
}