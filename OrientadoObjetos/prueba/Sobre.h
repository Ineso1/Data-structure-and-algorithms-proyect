#ifndef SOBRE_H
#define SOBRE_H
#include <iostream>
#include "Envio.h"
#include "Persona.h"

using namespace std;

class Sobre:public Envio{
    private:
    int la, an, costoExtra;

    public:
    Sobre();
    Sobre( double, Persona, Persona, int, int, int);

    int getLa() const;
    int getAn() const;
    int getCostoExtra() const;

    void setLa(int);
    void setAn(int);
    void setCostoExtra(int);

    void mostrarS();
    double calculaCosto();
};
#endif