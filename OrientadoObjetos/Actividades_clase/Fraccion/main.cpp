//Ines Alejandro Garcia Mosqueda A00834571

//Realiza el main para probar todos los operadores
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Fraccion.h"
#include "ArrayFracc.h"

using namespace std;

void cargaDatos(ArrayFracc& misFracciones){
    //Llena con esta función los datos del objeto misFracciones
    //con la lectura de un archivo de texto
    Fraccion frac;
    ifstream archivo;
    archivo.open("datosFracc.txt");
    if (archivo.is_open()){
        while (archivo >> frac) {
            misFracciones.agregaFraccion(frac);
        }}
    archivo.close();
}
//Puedes crear más funciones si las requieres...

//Llena la función principal para hacer todas tus pruebas
int main() {
    
    //llena los datos de un ArrayFracc y prueba el operador de indexación
    ArrayFracc arrFrac;
    cargaDatos(arrFrac);
    for (int i = 0; i<3; i++){
    cout << arrFrac[i] <<endl;
    }
    //Crea dos fracciones con datos que recibas del usuario
    Fraccion f1, f2;
    cout << "Fracion 1:\n";
    cin >> f1;
    cout << "Fracion 2:\n";
    cin >> f2;
    cout << endl;

     //Prueba los distintos operadores de la clase Fracción haz un menu para
    //que el usuario decida qué operación quiere realizar con estas dos fracciones
    bool menu = true;
    while(menu){ 
        cout << "Que funcion deseas probar?\n1. +\n2. -\n3. ++ (prefijo)\n4. ++ (postfijp)\n5. -- (preincremento)\n6. -- (postincremento)\n7. >\n8.==\n";
        int op;
        char vacio;
        cin >> op;

        switch (op){
            case 1:
                cout << "\n" << (f1 + f2);
            break;
            case 2:
                cout << "\n" << (f1 - f2);
            break;
            case 3:
                ++ f1;
            break;
            case 4:
                f1 ++;
            break;
            case 5:
                -- f1;
            break;
            case 6:
                f1 --;
            break;
            case 7:
                cout << "Resultado boleano: " <<  (f1 > f2);
            break;
            case 8:
                cout << "Resultado boleano: " << (f1 == f2);
            break;
            default:
                cout << "\nNo existe la opcion\n" << endl;
                menu = false;
        }
        cout << "\n" << f1 << "  "  << f2 << endl;
        cout << "\nPresiona enter\n";
        system("pause");
    }


    return 0;
}