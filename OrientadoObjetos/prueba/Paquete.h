#ifndef PAQUETE_H
#define PAQUETE_H
#include "Envio.h"
#include "Persona.h"
#include <iostream>

using namespace std;

class Paquete:public Envio{
    private:
        int la, an, prf, peso, costoK;

    public:

        Paquete();
        Paquete(Persona, Persona, double, int, int, int, int, int);

        int getLa() const;
        int getAn() const;
        int getPrf() const;
        int getPeso() const;
        int getCostoK() const;
        Persona getRemt() const;
        Persona getDest() const;
        double getCostoE() const;
    
        void setLa(int);
        void setAn(int);
        void setPrf(int);
        void setPeso(int);
        void setCostoK(int);
        void setRemt(Persona);
        void setDest(Persona);
        void setCostoE(double);

        //metodos.
        double calculaCosto();
        void mostrarP();
};
#endif
