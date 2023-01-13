/**
 * @file Sobre.h
 * @author Ines ALejandro Garcia Mosqueda (A00834571@tec.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Persona.h"
#include "Paquete.h"
#include "Sobre.h"
#include "Envio.h"
#include <iostream>

using namespace std;

Persona p1 ("Ines", "Juventino Rosas", "38240");
Persona p2 ("Carlos", "North Carolina", "27514");

int main()
{
    double largo = 5;
    double ancho = 5; 
    double profundidad = 100;
    double peso = 3;
    double costoKilogramo = 25;
    double costoEstandarEnvio = 50;
    double cargoAdicional = 150;

    Paquete paquete_objeto_sinEnvio(largo, ancho, profundidad, peso, costoKilogramo, p1, p2, 0);
    Paquete paquete_objeto(largo, ancho, profundidad, peso, costoKilogramo, p1, p2, costoEstandarEnvio);
    Sobre sobre_objeto(cargoAdicional, largo, ancho, p1, p2, costoEstandarEnvio);
    
    cout << "........Diferencias de precios........\n";
    cout << "Paquete sin costo envio: " << paquete_objeto_sinEnvio.calculaCosto() << endl;
    cout << "Paquete: " << paquete_objeto.calculaCosto() << endl;
    cout << "Sobre: " << sobre_objeto.calculaCosto() << endl;

    cout << "........Paquete sin costo........";
    cout << endl << paquete_objeto_sinEnvio.datos();
    cout << "........Paquete con costo........";
    cout << endl << paquete_objeto.datos();
    cout << "..............Sobre..............";
    cout << endl << sobre_objeto.datos();
}