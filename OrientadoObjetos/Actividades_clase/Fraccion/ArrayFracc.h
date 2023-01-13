//Ines Alejandro Garcia Mosqueda A00834571

#ifndef ARRAYFRACC_H
#define ARRAYFRACC_H
#include <iostream>
#include <vector> 
#include "Fraccion.h"

class ArrayFracc{
    public:
        ArrayFracc();
        void agregaFraccion(Fraccion &);
        Fraccion &operator[](int);
    private:
        std::vector<Fraccion> fracciones; 
};

#endif //ARRAYFRACC_H