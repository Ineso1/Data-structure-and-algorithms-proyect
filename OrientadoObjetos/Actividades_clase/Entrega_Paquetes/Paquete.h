/*
La  Clase  Derivada  Paquete  debe  heredar  la  funcionalidad  de  la  clase  base  Envio,  pero 
también debe incluir datos miembros que representan largo, ancho y profundidad, peso y 
costo  por  kilogramo.  El  constructor  de  la  clase  Paquete  debe  recibir  estos  valores  para 
inicializar  éstos  datos  miembros.  Asegúrese  de  que  el  peso  y  el  costo  por  kilogramo 
contengan  valores  positivos.  La  función  calculaCosto debe  redefinirse para  determinar  el 
costo  multiplicando  el  peso  por  el  costo  por  kilogramo  y  sumarlo  al  costo  estándar  por 
envío. 
*/

#ifndef PAQUETE_H
#define PAQUETE_H
#include <iostream>
#include "Envio.h"

class Paquete:public Envio{
    public:
    Paquete();
    Paquete(double ,double ,double, double, double, Persona, Persona, double);
    double getLargo() const;
    double getAncho() const;
    double getProfundidad() const;
    double getPeso() const;
    double getCostoKilogramo() const;
    void setLargo(double);
    void setAncho(double);
    void setProfundidad(double);
    void setPeso(double);
    void setCostoKilogramo(double);
    double calculaCosto();
    std::string datos();


    private:
    double largo;
    double ancho;
    double profundidad;
    double peso;
    double costoKilogramo;

};

#endif //PAQUETE_H