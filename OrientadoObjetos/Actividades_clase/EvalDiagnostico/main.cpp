/*
Ines Alejandro Garcia Mosqueda
A00834571
*/

#include "Complejo.h"
#include <iostream>

using namespace std;

int main(){
    //Declaracion de numero complejo
    Complejo numComplejo_1 = Complejo(3,5);
    Complejo numComplejo_2 = Complejo(5,-12);
    cout << "........Numeros complejos........" << endl;
    //Impresion de numero complejo
    numComplejo_1.imprime();
    numComplejo_2.imprime();
    cout << ".......Conjugados........." << endl;
    //Impresion de complejo conjudado
    numComplejo_1.conjugado().imprime();
    numComplejo_2.conjugado().imprime();
    cout << "........Suma........" << endl;
    //Suma
    numComplejo_1.suma(numComplejo_2).imprime();
    cout << "........Multiplicacion........" << endl;
    //Multiplicacion
    numComplejo_1.multiplicacion(numComplejo_2).imprime();
    cout << "........Multiplicacion x escalar........" << endl;
    //Multiplicacion x escalar
    double numEscalar = 2;
    numComplejo_1.multiEscalar(numEscalar).imprime();
    numComplejo_2.multiEscalar(numEscalar).imprime();
    cout << "........Agregar........" << endl;
    //Agregar
    numComplejo_1.agregar(numComplejo_2);
    numComplejo_1.imprime();
    cout << "................" << endl;
}