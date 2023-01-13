#ifndef RECTANGLE_h
#define RECTANGLE_h
#include "Shape.h"

class Rectangle:public Shape{
    public:
    Rectangle();
    Rectangle(int ,int ,int, int);
    int getWidth() const;
    void setWidth(int);
    int getHeight() const;
    void setHeight(int);
    double area() override;
    std::string draw() override;

    private:
    int width;
    int height;

};

#endif //RECTANGLE_h