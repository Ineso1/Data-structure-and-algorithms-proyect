// Ines Alejandro Garcia Mosqueda
// A00834571
//Listas doblemente ligadas+

#include <iostream>
#include <fstream>
using namespace std;

//Clase Nodo doblemente ligado
class Node{
    public:
    int data;
    Node *nextNode;
    Node *previousNode;
    Node();
    Node(int,Node*,Node*);
    int getData();
    void setData(int);
    ~Node();
};

//Constructor Nodo
Node::Node(){
    // data = nullptr;
    data = 0;
    nextNode = nullptr;
    previousNode = nullptr;
}

//Sobrecarga nodo
Node::Node(int data, Node* prev, Node* next) {
    this->data = data;
    this->nextNode = next;
    this->previousNode = prev;
}

//Destructor Nodo
Node::~Node(){
    delete &data;
    delete nextNode;
    delete previousNode;
}

//Geter de datos de la lista
int Node::getData(){
    int num = this->data;
    return num;
}

//Seter de datos de la lista
void Node::setData(int data){
    this->data = data;
}

//Lista Ligada
class LinkedList{
    public:
        LinkedList();
        Node* head;
        int len = 0;
        Node* insertBefore(Node*, int);
        Node* insertAfter(Node*, int);
        void fillList(string);
        void printList();
        int search(int);
        Node &operator[](int);
        void update(int, int);
        void deleteNode(int);
};

//Constructor Lista ligada
LinkedList::LinkedList(){
    this->head = NULL;
}

//Funcion insertar un nodo despues de otro nodo dado
// Complejidad O(1)
//apartir de un nodo dado inserta uno despues
Node* LinkedList::insertAfter(Node* beforeNode, int data){
    Node *newNode = new Node();
    newNode->setData(data);
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

//Funcion insertar un nodo antes de otro nodo dado
// Complejidad O(1)
//apartir de un nodo dado inserta uno antes
Node* LinkedList::insertBefore(Node* afterNode, int data){
    Node *newNode = new Node();
    newNode->setData(data);    
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

//Lenado de lista ligada apartir de un archivo txt
// Complejidad O(n)
//apartir de un archivo dado carga la lista con datos
void LinkedList::fillList(string direccionArchivo){
    ifstream archivo;
    archivo.open(direccionArchivo);
    if (archivo.is_open()){
        int data;
        Node *tmp;
        if (archivo >> data)
        {
            Node *newNode = new Node();
            newNode->setData(data);
            newNode->nextNode = NULL;
            this->head = newNode;
            tmp = this->head;
        }

        while (archivo >> data)
        {
            tmp = insertAfter(tmp, data);
        }
    }
}

//Sobrecarga de operador (Falta manejo de excepciones)
// Complejidad O(n)
//apartir de un index dado accede a un nodo deseado
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
    cout<<" NULL ";
    while(tmp != NULL){
        cout<<" <-> "<<tmp->getData();
        tmp = tmp->nextNode;
    }
    cout<<" NULL "<<endl;
}

//Busqueda de un elemento (por numero/dato)
//Regresa el indice en la lista
// Complejidad O(n)
//apartir de un dato dado recorre la lista hasta encontrar el numero y regresa el index
int LinkedList::search(int data){
    Node* tmp;
    tmp = this->head;
    for (int i = 0; i < len; i++)
    {
        if (tmp->getData() == data)
        {
            return i;
        }
        tmp = tmp->nextNode;
    }
    throw "No existe en lista";
}

// Complejidad O(n)
//apartir de un index dado accede a un nodo deseado y actualiza con el dat dado
void LinkedList::update(int iter, int data){
    Node* tmp;
    tmp = this->head;
    for (int i = 0; i < iter && tmp != NULL; i++)
    {
        tmp = tmp->nextNode;
    }
    if (tmp != NULL)
    {
        tmp->setData(data);
    }
}


//Funcion de la lista ligada para ingresar un index de la lista y borrar dicho index
//Complejidad del algoritmo O(n)
//Recorre la lista en busca del incice para borrar
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

int main(){
    LinkedList ll;  //Crea una lista ligada
    ll.fillList("lista.txt");   //Lectura de archivo para carga de lista
    ll.printList(); //Impresion de la lista con datos del archivo
    cout<<"\nEl nodo en la posicion 2 es: "<<ll[2].getData()<<endl;     //Obtencion de datos apartir de un indice en la sobrecarga de operadores
    cout<<"\nEl nodo con el valor de 3 se encuentra en el index: "<<ll.search(3)<<endl; //Busqueda de un valor en especifico y retorna el indice en el que encuentra dicho numero
    ll.deleteNode(3);   //Algoritmo para borrar un nodo apartir de un indice dado
    ll.printList();
    ll.update(4, 200); //Funcion para cambiar valor de nodo principal, se le da el numero de nodo y consecutivamente el valor por el cuel cambiar
    ll.printList();

    return 0;
}