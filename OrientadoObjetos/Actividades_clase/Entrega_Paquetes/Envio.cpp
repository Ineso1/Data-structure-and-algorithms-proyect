#include "Envio.h"

Envio::Envio(){
    remitente = Persona();
    cliente = Persona();
    costo = 20;
}

Envio::Envio(Persona _remitente, Persona _cliente, double _costo){
    remitente = _remitente;
    cliente = _cliente;
    costo = _costo;
}

Persona Envio::getRemitente() const{
    return remitente;
}

Persona Envio::getCliente() const{
    return cliente;
}

double Envio::getCosto() const{
    return costo;
}

void Envio::setRemitente(Persona _remitente){
    remitente = _remitente;
}

void Envio::setCliente(Persona _cliente){
    cliente = _cliente;
}

void Envio::setCosto(double _costo){
    costo = _costo;
}

double Envio::calculaCosto(){
    return costo;
}

std::string Envio::datos(){
    return "\nCliente:\n" + cliente.datos() + "\n" + "Remitente:\n" + remitente.datos() + "\n" + "Costo base: " + std::to_string(costo) + "\n\n\n";
}