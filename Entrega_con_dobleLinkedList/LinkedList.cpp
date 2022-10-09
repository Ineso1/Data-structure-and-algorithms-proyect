#include "LinkedList.h"
#include <fstream>
#include <sstream>
#include <string>

//Constructor Lista ligada
LinkedList::LinkedList(){
    this->head = NULL;
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

/*
LLenado de lista ligada apartir de un archivo txt
Complejidad O(n)
apartir de un archivo dado carga la lista con datos
fillList(archivo del cual se va a leer);
*/
void LinkedList::fillList(std::string direccionArchivo){
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
    // tmp->~Node();
}

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

int LinkedList::sortNodeIp(Node* &current){
    Node *tmp = head;
    while(tmp->nextNode !=NULL){
        int tmpDate = tmp->ipIntCode();
        int tmpNextNodeDate = tmp->nextNode->ipIntCode();
        int currentDate = current->ipIntCode();
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