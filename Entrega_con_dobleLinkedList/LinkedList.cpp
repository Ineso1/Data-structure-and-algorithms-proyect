#include "LinkedList.h"
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

//Constructor Lista ligada
LinkedList::LinkedList(){
    this->head = NULL;
    this->tail = NULL;
}

/*
Funcion insertar un nodo despues de otro nodo dado
Complejidad O(1)
Apartir de un nodo dado inserta uno despues
insertAfter(Nodo actual, datos de nuevo nodo);
CurrentNodo <-> NewNodo
*/
Node* LinkedList::insertAfter(Node* beforeNode, std::string month, std::string day, std::string hour, std::string ip, std::string reason){
    Node *newNode = new Node();
    newNode->setData(month, day, hour, ip, reason);
    newNode->nextNode = beforeNode->nextNode;
    newNode->previousNode = beforeNode;
    if (beforeNode->nextNode != NULL)
    {
        beforeNode->nextNode->previousNode = newNode;
    }
    beforeNode->nextNode = newNode;
    this->tail = newNode; 
    len++;
    return newNode;
}

Node* LinkedList::insertAfter(Node* beforeNode, Node* newNode){
    newNode->nextNode = beforeNode->nextNode;
    newNode->previousNode = beforeNode;
    if (beforeNode->nextNode != NULL)
    {
        beforeNode->nextNode->previousNode = newNode;
    }
    beforeNode->nextNode = newNode;
    this->tail = newNode; 
    len++;
    return newNode;
}

/*
Funcion insertar un nodo antes de otro nodo dado
Complejidad O(1)
apartir de un nodo dado inserta uno antes 
insertBefore(Nodo actual, datos de nuevo nodo);
NewNodo <-> CurrentNodo
*/
Node* LinkedList::insertBefore(Node* afterNode, std::string month, std::string day, std::string hour, std::string ip, std::string reason){
    Node *newNode = new Node();
    newNode->setData(month, day, hour, ip, reason);    
    newNode->nextNode = afterNode;
    newNode->previousNode = afterNode->previousNode;
    if (afterNode->previousNode != NULL)
    {
        afterNode->previousNode->nextNode = newNode;
    }
    else
    {
        head = newNode;
    }
    afterNode->previousNode = newNode;
    len++;

    return newNode;
}

Node* LinkedList::insertBefore(Node* afterNode, Node* newNode){
    newNode->nextNode = afterNode;
    newNode->previousNode = afterNode->previousNode;
    if (afterNode->previousNode != NULL)
    {
        afterNode->previousNode->nextNode = newNode;
    }
    else
    {
        head = newNode;
    }
    afterNode->previousNode = newNode;
    len++;

    return newNode;
}

/*
LLenado de lista ligada apartir de un archivo txt
Complejidad O(n)
apartir de un archivo dado carga la lista con datos
fillList(archivo del cual se va a leer);
*/
void LinkedList::fillList(std::string direccionArchivo){
    int charge = 0;
    std::ifstream archivo;
    archivo.open(direccionArchivo);
    if (archivo.is_open()){
        std::string month, day, hour, ip, reason;
        Node *tmp;
        if (archivo >> month>> day>> hour>> ip)
        {
            std::getline(archivo, reason);
            Node *newNode = new Node();
            newNode->setData(month, day, hour, ip, reason);
            newNode->nextNode = NULL;
            this->head = newNode;
            tmp = this->head;
        }

        while (archivo >> month>> day>> hour>> ip)
        {
            std::getline(archivo, reason);
            Node *newNode = new Node();
            newNode->setData(month, day, hour, ip, reason);
            sortNodeIp(newNode);
            //std::cout<<tail->ip;
            if (++charge%30 == 0){
                system("CLS");
                std::cout<<"..."<< (charge*100/16807)<<"%";
            }
            //sortNodeDate(newNode);
        }
    }
}

/*
Sobrecarga de operador (Falta manejo de excepciones)
Complejidad O(n)
apartir de un index dado accede a un nodo deseado
nombre[indice];
*/
Node &LinkedList::operator[](int index){
    if (index > len){
        throw("No existe el nodo con index " + index);
    }
    Node* tmp;
    tmp = this->head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->nextNode;
    }
    return *tmp;

}

//Impresion de la lista generada
void LinkedList::printList(){
    Node* tmp;
    tmp = this->head;
    std::cout<<" NULL ";
    while(tmp != NULL){
        std::cout<<" <-> "<< std::endl <<tmp->getData();
        tmp = tmp->nextNode;
    }
    std::cout<<" NULL "<<std::endl;
}

/*
Busqueda de un elemento (por numero/dato)
Regresa el indice en la lista
Complejidad O(n)
apartir de un dato dado recorre la lista hasta encontrar el numero y regresa el index
search(dato a buscar);
*/

int LinkedList::search(std::string month, std::string day, std::string hour, std::string ip, std::string reason){
    Node* tmp;
    tmp = this->head;
    for (int i = 0; i < len; i++)
    {
        if (tmp->getData() == month + " " + day + " " + hour + " " + ip + " " + reason)
        {
            return i;
        }
        tmp = tmp->nextNode;
    }
    throw "No existe en lista";
}

/*
Complejidad O(n)
apartir de un index dado accede a un nodo deseado y actualiza con el dat dado
update(indice del nodo, datos a sobrescribir);
*/
void LinkedList::update(int iter, std::string month, std::string day, std::string hour, std::string ip, std::string reason){
    Node* tmp;
    tmp = this->head;
    for (int i = 0; i < iter && tmp != NULL; i++)
    {
        tmp = tmp->nextNode;
    }
    if (tmp != NULL)
    {
        tmp->setData(month, day, hour, ip, reason);
    }
}


/*
Funcion de la lista ligada para ingresar un index de la lista y borrar dicho index
//Complejidad del algoritmo O(n)
//Recorre la lista en busca del incice para borrar (internamente enlaza nodos relacionados al q se borra)
deleteNode(indice a borrar);
*/
void LinkedList::deleteNode(int index){
    if (index > len){
        throw("No existe el nodo con index " + index);
    }
    Node* tmp;
    tmp = this->head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->nextNode;
    }

    tmp->nextNode->previousNode = tmp->previousNode;
    tmp->previousNode->nextNode = tmp->nextNode;
    tmp->~Node();
}

/*
Funcion de ordenamiento de acuerdo a fecha
Inserta el nodo dado por parametros de acuerddo a la fecha 
Complejidad(n)
*/
int LinkedList::sortNodeDate(Node* &current){
    Node *tmp = head;
    while(tmp->nextNode !=NULL){
        int tmpDate = tmp->dateIntCode();
        int tmpNextNodeDate = tmp->nextNode->dateIntCode();
        int currentDate = current->dateIntCode();
        if(tmpDate >= currentDate && currentDate > tmpNextNodeDate){
            insertAfter(tmp, current);
            return 0;
        }
        else if(tmpDate < currentDate){
            current->nextNode = head; 
            head = current;
            return 0;
        }
        tmp = tmp->nextNode;
    }
    tmp->nextNode = current;
    tmp = tmp->nextNode;
    return -1;
}

/*
Funcion de ordenamiento de acuerdo a Ip
Inserta el nodo dado por parametros de acuerddo a la fecha 
Complejidad(n)
*/
int LinkedList::sortNodeIp(Node* &current){
    Node *tmp = head;
    while(tmp->nextNode !=NULL){
        unsigned long long  tmpDate = tmp->ipIntCode();
        unsigned long long tmpNextNodeDate = tmp->nextNode->ipIntCode();
        unsigned long long currentDate = current->ipIntCode();
        if(tmpDate >= currentDate && currentDate > tmpNextNodeDate){
            insertAfter(tmp, current);
            return 0;
        }
        else if(tmpDate < currentDate){
            current->nextNode = head; 
            head = current;
            return 0;
        }
        tmp = tmp->nextNode;
    }
    tmp->nextNode = current;
    tmp = tmp->nextNode;
    return -1;
}


//Funcion de prueba para optimizar algoritmo de ordenamiento usando two pointer aproach
int LinkedList::sortNodeIp2(Node* &current){
    Node *tmpForward = head;
    Node *tmpBackward = tail;
    while(tmpForward != tmpBackward){
        unsigned long long  tmpForwardDate = tmpForward->ipIntCode();
        unsigned long long tmpForwardNextNodeDate = tmpForward->nextNode->ipIntCode();
        unsigned long long  tmpBackwardDate = tmpBackward->ipIntCode();
        unsigned long long tmpBackwardNextNodeDate = tmpBackward->previousNode->ipIntCode();
        unsigned long long currentDate = current->ipIntCode();

        if(tmpForwardDate >= currentDate && currentDate > tmpForwardNextNodeDate){
            insertAfter(tmpForward, current);
            return 0;
        }
        else if(tmpForwardDate < currentDate){
            current->nextNode = head; 
            head = current;
            return 0;
        }
        else if(tmpBackwardDate <= currentDate && currentDate < tmpBackwardNextNodeDate){
            insertBefore(tmpBackward, current);
            return 0;
        }

        tmpForward = tmpForward->nextNode;
        tmpBackward = tmpBackward->previousNode;
    }
    tmpForward->nextNode = current;
    tmpForward = tmpForward->nextNode;
    return -1;
}


/*
creación / Sobre escritura de un archivo txt para almacenamiento de información
Recorre toda la lista guardando los datos en un archivo txt
Complejidad O(n)
*/
void LinkedList::saveSortedList(){
    std::ofstream file;
    file.open("sorted.txt");
    Node *tmp = head;
    while(tmp !=NULL){
        file << tmp->month << " " 
        << tmp->day << " " 
        << tmp->hour << " " 
        << tmp->ip 
        << tmp->reason <<"\n";
        tmp = tmp->nextNode;
    }
    file.close();
}

/*
Filtro de búsqueda de Ip por rango de Ip
Recorre la lista hasta encontras direcciones Ip dentro del rango dado
Primero ordena los rangos de menor a mayor
Complejidad O(n)
*/
void LinkedList::findRangeIp(std::string ip1,std::string ip2){
    Node *tmp = head;
    Node *ini = new Node();
    Node *fin = new Node();
    std::string empty;
    ini->setData(empty, empty, empty, ip1, empty);
    fin->setData(empty, empty, empty, ip2, empty);
    std::ofstream file;
    file.open("resultadoBusqueda.txt");
    while (tmp !=NULL)
    {   
        if(ini->ipIntCode() > fin->ipIntCode()){
            Node* aux;
            aux = ini;
            ini = fin;
            fin = ini;
        }
        if (ini->ipIntCode() < tmp->ipIntCode() && tmp->ipIntCode() < fin->ipIntCode())
        {
            file << tmp->month << " " 
            << tmp->day << " " 
            << tmp->hour << " " 
            << tmp->ip 
            << tmp->reason <<"\n";
            tmp = tmp->nextNode;
        }
        tmp = tmp->nextNode;
    }
}
