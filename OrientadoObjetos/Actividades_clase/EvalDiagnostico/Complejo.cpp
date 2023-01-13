/*
Ines Alejandro Garcia Mosqueda
A00834571
*/

#include <iostream>
#include "Complejo.h"

using namespace std;

Complejo::Complejo(){
    real =  0;
    imaginario = 0;
}

Complejo::Complejo(double _real, double _imaginario){
    real = _real;
    imaginario = _imaginario;
}

double Complejo::getReal() const{
    return real;
}

double Complejo::getImaginario() const{
    return imaginario;
}

void Complejo::setReal(double _real){
    real = _real;
}

void Complejo::setImaginario(double _imaginario){
    imaginario = _imaginario;
}

void Complejo::agregar(Complejo _complejo){
    real += _complejo.getReal();
    imaginario += _complejo.getImaginario();
}

Complejo Complejo::conjugado(){
    double _real = real;
    double _imaginario = imaginario *= -1;
    return Complejo(_real,_imaginario);
}

Complejo Complejo::suma(Complejo _complejo){
    double _real = real + _complejo.getReal();
    double _imaginario = imaginario + _complejo.getImaginario();
    return Complejo(_real,_imaginario);
}

Complejo Complejo::multiplicacion(Complejo _complejo){
    double _real = (real * _complejo.getReal()) - (imaginario * _complejo.getImaginario());
    double _imaginario = (real * _complejo.getImaginario()) + (imaginario * _complejo.getReal());
    return Complejo(_real,_imaginario);
}

Complejo Complejo::multiEscalar(double escalar){
    double _real = real * escalar;
    double _imaginario = imaginario * escalar;
    return Complejo(_real, _imaginario);
}

void Complejo::imprime(){
    if( imaginario < 0){
        cout<<"("<<real<<" - "<<imaginario*(-1)<<"i"<<")"<<endl; 
    }
    else{
        cout<<"("<<real<<" + "<<imaginario<<"i"<<")"<<endl;
    }
}
