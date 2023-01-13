#include "Persona.h"

Persona::Persona(){
    nombre = "";
    ciudad = "";
    codigoPostal = "";
}

Persona::Persona(std::string _nombre, std::string _ciudad, std::string _codigoPostal){
    nombre = _nombre;
    ciudad = _ciudad;
    codigoPostal = _codigoPostal;
}

std::string Persona::getNombre() const{
    return nombre;
}

std::string Persona::getCiudad() const{
    return ciudad;
}

std::string Persona::getCodigoPostal() const{
    return codigoPostal;
}

void Persona::setNombre(std::string _nombre){
    nombre = _nombre;
}

void Persona::setCiudad(std::string _ciudad){
    ciudad = _ciudad;
}

std::string Persona::datos(){
    return "Nombre: " + nombre + "\n" + "Ciudad: " + ciudad + "\n" + "CodigoPostal: " + codigoPostal + "\n";
}
