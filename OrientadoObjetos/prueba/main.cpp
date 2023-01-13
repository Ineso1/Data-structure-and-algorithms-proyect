#include <iostream>
#include "Envio.h"
#include "Persona.h"
#include "Paquete.h"
#include "Sobre.h"

using namespace std;

int main(){

    int tipoE;

    cout << "¿Qué tipo de envío te gustaría hacer?" <<endl;
    cout << "1. Sobre" << endl;
    cout << "2. Paquete" << endl;

    cin >> tipoE;

    string nombreR, nombreD, ciudadR, ciudadD;
    int costoE, la, an, prf, peso, extra, costoK, cp_D, cp_R;
    

    bool sobre = (tipoE ==1);
    bool paquete = (tipoE == 2);

    if (sobre) {
    system("clear");
        costoE = 80;
        extra = 20;
        
        cout << "Introduce el largo del sobre: " << endl;
        cin >> la;

        cout << "Introduce el ancho del sobre: " << endl;
        cin >> an;
    }

    else if(paquete){
    system("clear");
        costoE = 150;
        costoK = 50;

        cout << "Introduce el largo del paquete: " << endl;
        cin >> la; 

        cout << "Introduce el ancho del paquete: " << endl;
        cin >> an; 

        cout << "Introduce la profundidad del paquete: " << endl;
        cin >> prf;

        cout << "Introduce el peso del paquete: " << endl;
        cin >> peso;

    }
   

    cout << "Introduce el nombre del destinatario: " << endl;
    cin  >> nombreD;
    cout << "Introduce la ciudad del destinatario: " << endl;
    cin >> ciudadD;
    cout << "Introduce el código postal del destinatario: " << endl;
    cin >> cp_D;

   Persona dest (nombreD, ciudadD, cp_D);
   system ("clear");

    
    cout << "Introduce el nombre del remitente: " << endl;
    cin >> nombreR;
    cout << "Introduce la ciudad del remitente: " << endl;
    cin >> ciudadR;
    cout << "Introduce el código postal del remitente:  " << endl;
    cin >> cp_R;

   Persona remt (nombreR, ciudadR, cp_R);
   system("clear");

    

    if(sobre){
        system("clear");

        Sobre sobre(costoE, dest, remt, la, an, extra);

        sobre.mostrarS();
    }
    else if(paquete){
        system("clear");

        Paquete paquete(remt, dest, costoE, an, la, prf, peso, costoK);
        
        paquete.mostrarP();
    }
   

}