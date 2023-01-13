
#include "CoordPolar.h"

CoordPolar::CoordPolar(){
    r=0;
    angulo=0;
}
CoordPolar::CoordPolar(double rr, double a){
    r=rr;
    angulo=a;
}
double CoordPolar::getR() const{
    return r;
}
double CoordPolar::getAngulo() const{
    return angulo;
}
void CoordPolar::setR(double rr){
    r=rr;
}
void CoordPolar::setAngulo(double a){
    angulo=a;
}

CoordRect CoordPolar::convertirRect(){
    double x = r * cos(angulo);
    double y = r * sin(angulo); 
    return CoordRect (x,y);
}
