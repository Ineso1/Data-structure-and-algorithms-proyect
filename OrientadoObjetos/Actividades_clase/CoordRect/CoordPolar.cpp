
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

CoordPolar CoordPolar:: operator* (const CoordPolar& cp){
    return CoordPolar(this -> r * cp.getR(), this -> angulo + cp.getAngulo());
}

ostream& operator <<(ostream& os, const CoordPolar& cr){
    os << "(" << cr.r <<", "<<cr.angulo<<")";
    return os;
}
