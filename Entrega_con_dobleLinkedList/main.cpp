//Ines Aljandro Garcia Mosqueda A00834571
//Jesus Fong Ruiz A01254062s
#include <iostream>
#include "LinkedList.h"
using namespace std;



int main(){
    LinkedList ll;  //Crea una lista doblemente ligada
    ll.fillList("bitacoraPrueba.txt");   //Lectura de archivo para carga de lista
    ll.printList(); //Impresion de la lista con datos del archivo
    //cout<<"\nEl nodo en la posicion 2 es: "<<ll[2].getData()<<endl;     //Obtencion de datos apartir de un indice en la sobrecarga de operadores
    //cout<<"\nEl nodo con el valor de 3 se encuentra en el index: "<<ll.search(3)<<endl; //Busqueda de un valor en especifico y retorna el indice en el que encuentra dicho numero
    //ll.deleteNode(3);   //Algoritmo para borrar un nodo apartir de un indice dado
    //ll.printList();
    //ll.update(4, 200); //Funcion para cambiar valor de nodo principal, se le da el numero de nodo y consecutivamente el valor por el cuel cambiar
    //ll.printList();
}