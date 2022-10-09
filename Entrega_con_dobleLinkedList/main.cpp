//Ines Aljandro Garcia Mosqueda A00834571
//Jesus Fong Ruiz A01254062s
#include <iostream>
#include "LinkedList.h"
using namespace std;



int main(){
    LinkedList ll;  //Crea una lista doblemente ligada
    // ll.fillList("bitacoraPrueba.txt");   //Lectura de archivo para carga de lista
    ll.fillList("bitacora.txt");   //Lectura de archivo para carga de lista
    ll.printList(); //Impresion de la lista con datos del archivo
    ll.saveSortedList();
    cout << "El resultado del ordenamiento fue guardado en un archivo llamado sorted.txt";


    string ip1, ip2;
    cout << "\n\t\tLista de peticiones\n";
    cout << "A continuacion se realizara una busqueda\nIntroduce el rango de la busqueda de Ip\nXXX.XXX.XXX.XX:XXXX --> ";
    cin >> ip1;
    cout << "\nXXX.XXX.XXX.XX:XXXX --> "; 
    cin >> ip2;
    try{
        ll.findRangeIp(ip1, ip2);
        }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": otro error por aqui" << '\n';
        return -1;
    }
    cout << "\nEl resultado del ordenamiento fue guardado en un archivo llamado resultadoBusqueda.txt\n";
    return 0;
}