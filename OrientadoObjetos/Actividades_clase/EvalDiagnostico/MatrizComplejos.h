/*
Ines Alejandro Garcia Mosqueda
A00834571
*/

#ifndef MATRIZCOMPLEJOS_h
#define MATRIZCOMPLEJOS_h

#include "Complejo.h"

class MatrizComplejos{
    public:
        MatrizComplejos();
        MatrizComplejos(int);
        bool validacion();
        int getN();
        void setN(int);
        Complejo getPos(int,int);
        void setPos(int,int,Complejo);
        MatrizComplejos suma(MatrizComplejos&);
        void agregaMatriz(MatrizComplejos&);
        void imprime();

    private:
        int n;
        Complejo ArregloComplejos [20][20];
};

#endif //MATRIZCOMPLEJOS_H