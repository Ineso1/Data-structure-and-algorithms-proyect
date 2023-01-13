#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

class Persona {
    public:
        Persona();
        Persona(std::string nombre, std::string ciudad, std::string cp);
        void imprime();
    private:
        std::string nombre;
        std::string ciudad;
        std::string cp;
};

#endif // PERSONA_H