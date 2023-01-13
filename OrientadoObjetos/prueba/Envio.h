#ifndef ENVIO_H
#define ENVIO_H
#include "Persona.h"
#include <iostream>

using namespace std;

class Envio {
    private:
        double costoE;
        Persona remt;
        Persona dest;
    
    public:
        Envio();
        Envio(double, Persona, Persona);

        double getCostoE() const;
        Persona getRemt() const;
        Persona getDest() const;
    
        void setCostoE(double);
        void setRemt(Persona);
        void setDest(Persona);
    
  
    
};
#endif 