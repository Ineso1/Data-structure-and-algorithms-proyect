#include "CoordRect.h"
CoordRect::CoordRect(){
    x=0;
    y=0;
}
CoordRect::CoordRect(double xx, double yy){
    x=xx;
    y=yy;
}
double CoordRect::getX() const{
    return x;
}
double CoordRect::getY() const{
    return y;
}
void CoordRect::setX(double xx){
    x=xx;
}
void CoordRect::setY(double yy){
    y=yy;
}

CoordRect CoordRect:: operator + (const CoordRect& otra){
    return CoordRect(this -> x + otra.x, this -> y + otra.y);
}

CoordRect CoordRect:: operator + (const CoordPolar& cp){
    return CoordRect (this -> x + cp.getR()*cos(cp.getAngulo()*M_PI/180),this -> y + cp.getR()*sin(cp.getAngulo()*M_PI/180));
}

ostream& operator <<(ostream& os, const CoordRect& cr){
    os << "(" << cr.x <<", "<<cr.y<<")";
    return os;
}