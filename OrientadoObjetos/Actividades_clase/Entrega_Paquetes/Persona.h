/*
 Datos  miembros  que  representen  el  nombre,  ciudad  y 
código  postal  tanto  del  remitente  como  del  destinatario  del  envío.  Para  lo  anterior  te 
recomiendo hacer una clase que se llame Persona o Cliente y que mantenga estos datos
*/
#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

class Persona{
    public:
    Persona();
    Persona(std::string ,std::string ,std::string);
    std::string getNombre() const;
    std::string getCiudad() const;
    std::string getCodigoPostal() const;
    void setNombre(std::string);
    void setCiudad(std::string);
    void setCodigoPostal(std::string);
    std::string datos();

    private:
    std::string nombre;
    std::string ciudad;
    std::string codigoPostal;

};

#endif //PERSONA_H