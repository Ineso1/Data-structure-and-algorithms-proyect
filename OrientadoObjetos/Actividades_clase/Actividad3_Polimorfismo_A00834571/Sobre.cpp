#include <iomanip>
#include "Sobre.h"

//Iniciamos constante de clase
const double Sobre::cargoAdicional = 79.90;

//Constructor por defecto
Sobre::Sobre(){
    ancho=0;
    largo=0;
}
//Constructor con parámetros
Sobre::Sobre(Persona& r, Persona& d, double an, double la):Envio(r,d){
    setAncho(an);
    setLargo(la);
}

double Sobre::getAncho() const{
    return ancho;
}

double Sobre::getLargo() const{
    return largo;
}

void Sobre::setAncho(double an){
    ancho = (an < 0)? 0 : an;
}

void Sobre::setLargo(double la){
    largo = (la < 0)? 0 : la;
}
//Sobreescribir calculaCosto de la clase envio
double Sobre::calculaCosto(){
    if(ancho>25 || largo>30){
        return cargoAdicional + Envio::calculaCosto();
    }
    return Envio::calculaCosto();
}

void Sobre::imprime(){
    Envio::imprime();
    std::cout << "Datos del sobre: "<< std::endl;
    std::cout << "\tAncho: " << ancho << " Largo: " << largo << std::endl;
    std::cout << "A PAGAR: $"<< std::setprecision(2) << std::fixed << calculaCosto();
}


