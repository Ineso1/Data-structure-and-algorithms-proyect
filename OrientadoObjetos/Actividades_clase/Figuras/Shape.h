
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape{
    public:
        Shape();
        Shape(int,int);
        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        virtual std::string draw();
        virtual double area() = 0;  //Abstracta

    private:
        int x;
        int y;
};

#endif //SHAPE_H