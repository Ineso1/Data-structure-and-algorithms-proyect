#include "Sobre.h"

Sobre::Sobre(){
    cargoAdicional = 0;
}

Sobre::Sobre(double _cargoAdicional, double _largo, double _ancho, Persona _remitente, Persona _cliente, double _costo):Envio( _remitente, _cliente, _costo){
    largo = _largo;
    ancho = _ancho;
    
    if(_largo > 25 || _ancho > 25){
        cargoAdicional = _cargoAdicional;
    }
    else{
        cargoAdicional = 0;
    }
}

double Sobre::getLargo() const{
    return largo;
}

double Sobre::getAncho() const{
    return ancho;
}

void Sobre::setLargo(double _largo, double _cargoAdicional){
    largo = _largo;
    if(_largo > 25){
        cargoAdicional = _cargoAdicional;
    }
    else{
        cargoAdicional = 0;
    }
}

void Sobre::setAncho(double _ancho, double _cargoAdicional){
    ancho = _ancho;
    if(_ancho > 25){
        cargoAdicional = _cargoAdicional;
    }
    else{
        cargoAdicional = 0;
    }
}

double Sobre::calculaCosto(){
    return Envio::calculaCosto() + cargoAdicional;
}

std::string Sobre::datos(){
    return "\n\t" + Envio::datos() + "Medidas: " + std::to_string(largo) + " x " + std::to_string(ancho) + "\nCargo adicional por medidas: " + std::to_string(cargoAdicional) + "\n\n";

}