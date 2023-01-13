#include "Paquete.h"

Paquete::Paquete(){
    largo = 1;
    ancho = 1;
    profundidad = 1;
    peso = 10;
    costoKilogramo = 10;
}

Paquete::Paquete(double _largo, double _ancho, double _profundidad, double _peso, double _costoKilogramo, Persona _remitente, Persona _cliente, double _costo):Envio( _remitente, _cliente, _costo){
    largo = _largo;
    ancho = _ancho;
    profundidad = _profundidad;
    peso = _peso;
    costoKilogramo = _costoKilogramo;
}

double Paquete::getLargo() const{
    return largo;
}

double Paquete::getAncho() const{
    return ancho;
}

double Paquete::getProfundidad() const{
    return profundidad;
}


double Paquete::getPeso() const{
    return peso;
}

double Paquete::getCostoKilogramo() const{
    return costoKilogramo;
}

void Paquete::setLargo(double _largo){
    largo = _largo;
}

void Paquete::setAncho(double _ancho){
    ancho = _ancho;
}

void Paquete::setProfundidad(double _profundidad){
    profundidad = _profundidad;
}

void Paquete::setPeso(double _peso){
    peso = _peso;
}

void Paquete::setCostoKilogramo(double _costoKilogramo){
    costoKilogramo = _costoKilogramo;
}

double Paquete::calculaCosto(){
    return peso * costoKilogramo + Envio::getCosto();
}

std::string Paquete::datos(){
    return "Paquete:\n\n" + Envio::datos() + "Medidas: " + std::to_string(largo) + " x " + std::to_string(ancho) + " x " + std::to_string(profundidad) + "\n" + "Peso: " + std::to_string(peso) + "\nCosto x Kilogramo: " + std::to_string(costoKilogramo) + "\n";
}