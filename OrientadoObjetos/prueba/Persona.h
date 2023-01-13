#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;

class Persona{
    private: 
        string nombre;
        string ciudad;
        int codigoP;

    public:
        Persona();
        Persona(string, string, int);

        string getNombre() const;
        string getCiudad() const;
        int getCodigoP() const;

        void setNombre(string);
        void setCiudad(string);
        void setCodigoP(int);
    //método
        void mostrarD();

};
#endif