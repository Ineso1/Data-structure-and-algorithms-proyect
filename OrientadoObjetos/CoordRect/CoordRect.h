#ifndef COORDRECT_H
#define COORDRECT_H
#include <iostream>
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
        CoordPolar convertirPolar();
//<Tipo_retorno> operator op (<tipo_parámetro>);
//friend <Tipo_retorno> operator op (<tipo_par>, <tipo_par>);
        CoordRect operator +(const CoordRect&);
        CoordRect operator +(const CoordPolar&);
        friend ostream &operator <<(ostream& salida, const CoordRect&);
    private:
        double x;
        double y;
};

#endif // COORDRECT_H