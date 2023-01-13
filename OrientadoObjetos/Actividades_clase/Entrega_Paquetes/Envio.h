/*
La  clase  base  Envio  debe  incluir  datos  miembros  que  representen  el  nombre,  ciudad  y 
código  postal  tanto  del  remitente  como  del  destinatario  del  envío.  Para  lo  anterior  te 
recomiendo hacer una clase que se llame Persona o Cliente y que mantenga estos datos, 
por lo que, con esto, deberías estar practicando también composición. Adicional a los datos 
de remitente y destinatario, el envío debe tener el costo estándar por envío. El constructor 
de la clase Envio debe inicializar estos valores en los datos miembros. 
La clase Envio debe proporcionar una función pública miembro llamada calculaCosto que 
devuelve un valor double indicando el costo asociado con el envío del paquete. 
*/

#ifndef ENVIO_H
#define ENVIO_H
#include <iostream>
#include "Persona.h"

class Envio{
    public:
    Envio();
    Envio(Persona ,Persona ,double);
    Persona getRemitente() const;
    Persona getCliente() const;
    double getCosto() const;
    void setRemitente(Persona);
    void setCliente(Persona);
    void setCosto(double);
    double calculaCosto();
    std::string datos();

    private:
    Persona remitente;
    Persona cliente;
    double costo;

};

#endif //ENVIO_H