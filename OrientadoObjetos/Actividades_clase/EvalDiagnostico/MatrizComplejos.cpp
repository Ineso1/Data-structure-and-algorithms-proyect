/*
Ines Alejandro Garcia Mosqueda
A00834571
*/

#include <iostream>
#include "Complejo.h"
#include "MatrizComplejos.h"

using namespace std;

MatrizComplejos::MatrizComplejos(){
    n = 2;
}

MatrizComplejos::MatrizComplejos(int _n){
    n = _n;
}

void MatrizComplejos::setN(int _n){
    n = _n;
}

int MatrizComplejos::getN(){
    return n;
}

Complejo MatrizComplejos::getPos(int _i, int _j){
    //Buscar en posiciones y regresar Complejo
    return ArregloComplejos[_i+1][_j+1];
}

void MatrizComplejos::setPos(int _i,int _j, Complejo _num){
    ArregloComplejos[_i][_j] = _num;
}

/*
MatrizComplejos MatrizComplejos::suma(){
    Complejo _arreglo;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            _arreglo[_i][_j] = 
    }
    }
}
*/



