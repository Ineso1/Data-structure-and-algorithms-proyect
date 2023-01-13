#ifndef COORDRECT_H
#define COORDRECT_H
#include <iostream>
#include <cmath>
#include "CoordPolar.h"
using std::ostream;
const double M_PI = 3.1416;

class CoordRect{
    public:
        CoordRect();
        CoordRect(double, double);
        double getX() const;
        double getY() const;
        void setX(double);
        void setY(double);
        CoordRect operator +(const CoordRect&);
        CoordRect operator +(const CoordPolar&);
        friend ostream &operator <<(ostream& salida, const CoordRect&);
    private:
        double x;
        double y;
};

#endif // COORDRECT_H