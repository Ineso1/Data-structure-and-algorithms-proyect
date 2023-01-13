#include <iomanip>
#include "Paquete.h"

//iniciamos la constante de clase
const double Paquete::costoPorKilo = 23.45;

Paquete::Paquete(Persona& r, Persona& d, double p, double an, double la, double pro):Envio(r,d){
    setPeso(p);
    setAncho(an);
    setLargo(la);
    setProfundidad(pro);
}

double Paquete::getPeso() const{
    return peso;
}

double Paquete::getAncho() const{
    return ancho;
}

double Paquete::getLargo() const{
    return largo;
}

double Paquete::getProfundidad() const{
    return profundidad;
}

void Paquete::setPeso(double p){
    peso = (p < 0)? 0 : p;
}

void Paquete::setAncho(double an){
    ancho = (an < 0)? 0 : an;
}

void Paquete::setLargo(double la){
    largo = (la < 0)? 0 : la;
}

void Paquete::setProfundidad(double pro){
    profundidad = (pro < 0)? 0 : pro;
}

double Paquete::calculaCosto(){
    return Envio::calculaCosto() + peso*costoPorKilo;
}

void Paquete::imprime(){
    Envio::imprime();
    std::cout << "Datos del paquete: " << std::endl;
    std::cout << "\tAncho: " << ancho << " Largo: " << largo 
    << " Profundidad: " << profundidad << " Peso: " << peso << std::endl;
    std::cout << "A PAGAR: $"<<std::setprecision(2) << std::fixed << calculaCosto() << std::endl;
}