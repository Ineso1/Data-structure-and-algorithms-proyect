#include "Rectangle.h"

Rectangle::Rectangle(){
    width = 1;
    height = 1;
}
Rectangle::Rectangle(int valX,int valY, int _width, int _height):Shape(valX, valY){
    height = _height;
    width = _width;
}

int Rectangle::getWidth() const{
    return width;
}

void Rectangle::setWidth(int _width){
    width = _width;
}

int Rectangle::getHeight() const{
    return height;
}

void Rectangle::setHeight(int _height){
    height = _height;
}

double Rectangle::area(){
    return height * width;
}

std::string Rectangle::draw(){
    return Shape::draw() + ": Rectangle\n";
}