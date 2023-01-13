#include <iostream>
#include "Persona.h"

using namespace std;

Persona::Persona(){
    nombre = "";
    ciudad = "";
    codigoP = 0;  
}

Persona::Persona(string n, string c, int cp){
    nombre = n;
    ciudad = c;
    codigoP = cp;
}

string Persona::getNombre() const{
    return nombre;
}
string Persona::getCiudad() const{
    return ciudad;
}
int Persona::getCodigoP() const{
    return codigoP;
}

void Persona::setNombre(string n){
    nombre = n;
}
void Persona::setCiudad(string c){
    ciudad = c;
}
void Persona::setCodigoP(int cp){
    codigoP= cp;
}

void Persona::mostrarD(){
    cout << "Nombre:   " << getNombre() << endl;
    cout << "Ciudad:   " << getCiudad() << endl;
    cout << "Código postal" << getCodigoP() << endl;
}