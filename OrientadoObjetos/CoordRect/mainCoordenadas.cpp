#include <iostream>
#include <vector>
#include <fstream>

#include "CoordRect.h"
#include "CoordPolar.h"
using namespace std;


int main(){

    vector <CoordRect*> listaRect;
    vector <CoordPolar*> listaPolar;

    double x, y;
    ifstream archivo;
    archivo.open("rectCoords.txt");
    if(archivo.is_open()){
        while(archivo){
            archivo >> x >> y;
            listaRect.push_back(new CoordRect(x, y));
        }
    }
    archivo.close();

    for (int i=0; i<listaRect.size();i++){
        cout << listaRect[i];
    }

    return 0;
}