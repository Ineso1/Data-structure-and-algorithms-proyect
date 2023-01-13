//Ines Alejandro Garcia Mosqueda A00834571

#include "ArrayFracc.h"

ArrayFracc::ArrayFracc(){
}

void ArrayFracc::agregaFraccion(Fraccion &f1){
    fracciones.push_back(f1);
}

Fraccion &ArrayFracc::operator[](int index){
    //Pon atención a cómo se hace en clase con la profesora.
    if (index>=0 && index<fracciones.size()){
        return fracciones[index];
    }
}