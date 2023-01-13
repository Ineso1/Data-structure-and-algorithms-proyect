#include <iostream>
#include "Envio.h"

using namespace std;

Envio::Envio(){
    costoE = 0;
    
}  
Envio::Envio( double ce, Persona r, Persona d){
    remt = r;
    dest = d;
    costoE = ce;
}

Persona Envio::getRemt() const{
    return remt;
}
Persona Envio::getDest() const{
    return dest;
}
double Envio::getCostoE() const{
    return costoE;
}

void Envio::setRemt(Persona r){
    remt = r;
}
void Envio::setDest(Persona d){
    dest = d;
}
void Envio::setCostoE(double ce){
    costoE = ce;
}

