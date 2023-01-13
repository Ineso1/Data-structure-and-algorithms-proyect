#include "Persona.h"

Persona::Persona() {
    nombre = "-";
    ciudad = "-";
    cp = "-";
}

Persona::Persona(std::string nom, std::string cd, std::string c) {
    nombre = nom;
    ciudad = cd;
    cp = c;
}

void Persona::imprime() {
    std::cout << "\tNombre: " << nombre << std::endl;
    std::cout << "\tDomicilio: "<< ciudad << " CP: "<< cp<< std::endl;
 }
