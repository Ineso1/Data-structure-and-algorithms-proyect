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

CoordPolar CoordRect::convertirPolar(){
    double r = sqrt((x*x) + (y*y));
    double angulo =  atan(y/x);
    return CoordPolar(r, angulo);
}

//<Tipo_retorno> NombreClase::operator op (<tipo_parámetro> var);
//En caso de ser operador unario no se recibe parámetro

//<Tipo_retorno> operator op (<tipo_par> var1, <tipo_par> var2){...}


CoordRect CoordRect:: operator +(const CoordRect& otra){
    return CoordRect(x + otra.x, y + otra.y);
}

CoordRect CoordRect:: operator +(const CoordPolar& otra){
    CoordPolar nOtra = otra;
    CoordRect n = nOtra.convertirRect();
    return CoordRect(x + n.x, y + n.y);
    
}

std::ostream& operator<<(std::ostream &salida, const CoordRect &coord){
    salida << " (" << coord.x << " , " << coord.y << " )" "\n";
}