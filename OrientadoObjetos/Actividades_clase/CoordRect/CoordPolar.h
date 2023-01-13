#ifndef COORDPOLAR_H
#define COORDPOLAR_H
#include <iostream>
using std::ostream;


class CoordPolar{

    public:
        CoordPolar();
        CoordPolar(double, double);
        double getR() const;
        double getAngulo() const;
        void setR(double);
        void setAngulo(double);
        CoordPolar operator *(const CoordPolar& cp);
        friend ostream &operator <<(ostream& salida, const CoordPolar&);
    private:
        double r;
        double angulo;
};

#endif // COORDPOLAR_H