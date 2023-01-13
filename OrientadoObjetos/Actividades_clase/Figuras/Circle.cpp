#include "Circle.h"

Circle::Circle(){
    radio = 1;
}
Circle::Circle(int valX,int valY, int r):Shape(valX, valY){
    radio = r;
}

int Circle::getRadio() const{
    return radio;
}

void Circle::setRadio(int r){
    radio = r;
}

double Circle::area(){
    return 3.1416 * radio * radio;
}

std::string Circle::draw(){
    return Shape::draw() + ": Circle\n";
}

double Circle::circunferencia(){
    return 2*3.1416*radio;
}