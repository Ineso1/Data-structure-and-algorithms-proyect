#include <iomanip>
#include "Envio.h"

const double Envio::costoEstandar = 150.50;

Envio::Envio(){}

Envio::Envio(Persona& r, Persona& d){
    rem=r;
    des=d;
}

double Envio::calculaCosto(){
    return costoEstandar;
}

void Envio::imprime(){
    std::cout << "REMITENTE:" << std::endl;
    rem.imprime();
    std::cout << "DESTINATARIO: " << std::endl;
    des.imprime();
    std::cout << "Costo base: $" << std::setprecision(2) << std::fixed<< costoEstandar << std::endl; 
}
