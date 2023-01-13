#include "Shape.h"


Shape::Shape(){
    x = 0;
    y = 0;
}

Shape::Shape(int _x,int _y){
    x = _x;
    y = _y;
}

int Shape::getX() const{
    return x;
}

int Shape::getY() const{
    return y;
}

void Shape::setX(int _x){
    x = _x;
}

void Shape::setY(int _y){
    y = _y;
}

std::string Shape::draw(){
    std::cout << "x: " << x << "\n";
    std::cout << "y: " << y << "\n";
    return "Soy una figura";
}
