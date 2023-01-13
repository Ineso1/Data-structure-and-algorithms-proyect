/*
Ines Alejandro Garcia Mosqueda
A00834571
*/

#ifndef COMPLEJO_h
#define COMPLEJO_h

class Complejo{
    public:
        Complejo();
        Complejo(double,double);

        double getReal() const;
        double getImaginario() const;
        void setReal(double);
        void setImaginario(double);
        void agregar(Complejo);
        Complejo conjugado();
        Complejo suma(Complejo);
        Complejo multiplicacion(Complejo);
        Complejo multiEscalar(double);
        void imprime();

    private:
        double real;
        double imaginario;
};

#endif //COMPLEJO_H