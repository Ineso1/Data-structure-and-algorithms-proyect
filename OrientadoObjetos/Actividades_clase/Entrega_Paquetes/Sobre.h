/*
La clase Sobre debe heredar directamente de la clase Envio. Sobre debe redefinir el cálculo 
de  la  función  miembro  calculaCosto  para  que  en  caso  de  que  las  dimensiones  del  sobre 
sean mayores a 25 * 30 cms en largo o en ancho, se agregue un cargo adicional. El cargo 
adicional debe ser un dato miembro de la clase Sobre. 
*/

#ifndef SOBRE_H
#define SOBRE_H
#include <iostream>
#include "Envio.h"

class Sobre: public Envio{
    public:
    Sobre();
    Sobre(double, double, double, Persona, Persona, double);
    
    double getLargo() const;
    double getAncho() const;
    double getCargoAdicional();
    void setLargo(double, double);
    void setAncho(double, double);
    void setCargoAdicional(double);
    double calculaCosto();
    std::string datos();


    private:
    double cargoAdicional;
    double largo;
    double ancho;

};

#endif //SOBRE_H