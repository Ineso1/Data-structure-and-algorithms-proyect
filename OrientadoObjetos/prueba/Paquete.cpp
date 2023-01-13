#include <iostream>
#include "Paquete.h"

using namespace std;

Paquete::Paquete(){
    la = 0;
    an = 0;
    prf = 0;
    peso = 0;
    costoK = 0;
}

Paquete::Paquete(Persona rt, Persona d, double ce, int l, int a, int pr, int pe, int ck):Envio(  ce, rt,  d){
    la = l;
    an = a;
    prf = pr;
    peso = pe;
    costoK = ck;
}

int Paquete::getLa() const{
    return la;
}
int Paquete::getAn() const{
    return an;
}
int Paquete::getPrf() const{
    return prf;
}
int Paquete::getPeso() const{
    return peso;
}
int Paquete::getCostoK() const{
    return costoK;
}

void Paquete::setLa(int _l){
    la = _l;
}
void Paquete::setAn(int _an){
    an = _an;
}
void Paquete::setPrf(int _pr){
    prf = _pr;
}
void Paquete::setPeso(int _pe){
    peso = _pe;
}
void Paquete::setCostoK(int _ck){
    costoK = _ck;
}

double Paquete::calculaCosto(){
    return ( peso * costoK ) + Envio::getCostoE();
}

void Paquete::mostrarP(){
    cout << "Mostrar datos del destinatario: ";
    Envio::getDest().mostrarD();
    cout << "Mostrar datos del remitente: ";
    Envio::getRemt().mostrarD();
    cout << "Largo del paquete: " << getLa() << endl;
    cout << "Ancho del paquete: " << getAn() << endl;
    cout << "Profundidad del paquete: " << getPrf() << endl;
    cout << "Peso del paquete: " << getPeso() << endl;
    cout << "Costo total: " << calculaCosto() << endl;
}