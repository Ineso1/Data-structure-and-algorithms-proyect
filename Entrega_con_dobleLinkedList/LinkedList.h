#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include "Node.h"

//Lista Ligada
class LinkedList{
    public:
        LinkedList();
        Node* head; //Nodo pricipal
        Node* tail; //Cola de la lista
        int len = 0; //Longitud de la lista
        Node* insertBefore(Node*, std::string, std::string, std::string, std::string, std::string); //inserta un nodo antes de otro dado la informacion del nodo nuevo
        Node* insertBefore(Node*, Node*); //Inserta un nodo antes de otro dado el nodo
        Node* insertAfter(Node*, std::string, std::string, std::string, std::string, std::string); //Inserta un nodo despues de otro nodo dado la informacion del nuevo nodo
        Node* insertAfter(Node*, Node*); //Inserta un nodo despues de otro nodo dado el nuevo nodo
        void fillList(std::string); //LLena la lista dado un archivo txt
        void printList(); //Imprime todos los datos de la lista
        int search(std::string, std::string, std::string, std::string, std::string); //Busca un nodo dados los datos del nodo
        Node &operator[](int); //Sobrecarga de operador para busqueda de un elemento en un indice dado
        void update(int, std::string, std::string, std::string, std::string, std::string); //Sobrescribe la informacion de un nodo dada la nueva informacion del nodo
        void deleteNode(int); //Algoritmo para borrar un nodo enlazando el resto de nodos
        int sortNodeDate(Node*&); //Algoritmo de ordenamiento por fecha
        int sortNodeIp(Node*&); //Algoritno de ordenamiento por Ip
        int sortNodeIp2(Node*&); //Intento de optimizacion de ordenamiento por Ip (en proceso)
        void saveSortedList(); //Creacion / Sobrescitura de un archivo txt para almacenamiento de informacion
        void findRangeIp(std::string, std::string); //Filtro de busqueda de Ip por rango de Ip
};

#endif // LINKEDLIST