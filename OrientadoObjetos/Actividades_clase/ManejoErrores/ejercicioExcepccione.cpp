#include <vector>
#include <iostream>
using namespace std;

void pruebaExcepcion1(){
    // manejo de excpecion estandar
  try  {
    throw 2;
  }
  catch (int e){
    cout << "Se prueba el MANEJO ESTANDAR de EXCEPCIONES, ha ocurrido la excepcion " << e << '\n';
  }
}

void pruebaExceptionCiclada(){
    int x, y;
    cout << "ingresa es dividendo: ";
    cin >> x;
    cout << "ingresa el divisor: ";
    cin >> y;
    while(true){
        try{
            if(y==0){
                throw "Division por cero, no puedo realizarlo";
            }
            int z=x/y;
            cout << "El resultado de la division es: " << z << endl;
            break;
        }
        catch(const char* msg){
            cerr << msg << endl;
            cout << "Ingresa otro denominador: ";
            cin >> y;
        }
    }
}

void pruebaExcepcion4(){
    int edad;
    cout << "Introduce tu edad: ";
    cin >> edad;
    try {
      if (edad >= 18) {
        cout << "Acceso permitido.";
      }
      else {
        throw (edad);
      }
    }
    catch (int numeroDelThrow) {
      cout << "Acceso denegado - debes tener 18 anios.\n";
      cout << "Edad: " << numeroDelThrow;
    }
}

int main(){
    vector<int> numeros;
    numeros.push_back(12);
 //MAnejo de las excepciones
    /*
    try {
        cout << numeros.at(3) << endl;
    }
    catch ( out_of_range &ex ) { 
        cerr << "Ocurrio una excepcion: " << ex.what() << endl; 
    }
    cout << "El programa continua" << endl;
    */
    //pruebaExcepcion1();
    //pruebaExceptionCiclada();
    pruebaExcepcion4();

}