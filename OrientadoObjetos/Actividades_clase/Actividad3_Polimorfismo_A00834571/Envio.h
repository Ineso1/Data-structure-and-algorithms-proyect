#ifndef ENVIO_H
#define ENVIO_H
#include "Persona.h"

class Envio{
    public:
        Envio();
        Envio(Persona&, Persona&);
        virtual double calculaCosto();
        virtual void imprime();
    private:
        static const double costoEstandar; //constante de clase
        Persona rem;
        Persona des;
};
#endif // ENVIO_H