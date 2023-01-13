#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle:public Shape{
    public:
    Circle();
    Circle(int ,int ,int);
    int getRadio() const;
    void setRadio(int);
    double area() override;
    std::string draw() override;
    double circunferencia();

    private:
    int radio;

};

#endif //CIRCLE_H