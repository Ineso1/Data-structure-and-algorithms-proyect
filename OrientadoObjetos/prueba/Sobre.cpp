#include <iostream>
#include "Sobre.h"

using namespace std;

Sobre::Sobre(){
    la = 0;
    an = 0;
    costoExtra = 0;
}

Sobre::Sobre(double ce, Persona d, Persona r, int l, int a, int c):Envio(ce, d, r){
    la = l;
    an = a;
    costoExtra = c;
}

int Sobre::getLa() const{
    return la;
}
int Sobre::getAn() const{
    return an;
}
int Sobre::getCostoExtra() const{
    return costoExtra;
}

void Sobre::setLa(int l){
    la = l;
}
void Sobre::setAn(int a){
    an = a;
}
void Sobre::setCostoExtra(int ex){
    costoExtra = ex;
}

double Sobre::calculaCosto(){
    
    if (getLa()*getAn() >= 750){
        return Envio::getCostoE() + costoExtra;
    }

    else {
        return Envio::getCostoE();
        
    }
 
}
void Sobre::mostrarS(){
    cout << "Nombre del remitente: " << endl;
    Envio::getRemt().mostrarD();
    cout << "Nombre del destinatario: " << endl;
    Envio::getDest().mostrarD();
    cout << "Largo del sobre: " << getLa() << endl;
    cout << "Ancho del sobre: " << getAn() << endl;
    cout << "Costo total del envío: " << calculaCosto() << endl; 
}
    

