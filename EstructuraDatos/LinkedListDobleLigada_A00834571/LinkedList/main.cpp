#include <iostream>
#include <fstream>
using namespace std;

//Clase Nodo doblemente ligado
class Node{
    public:
    int *data;
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
    data = nullptr;
    nextNode = nullptr;
    previousNode = nullptr;
}

//Sobrecarga nodo
Node::Node(int data, Node* prev, Node* next) {
    this->data = &data;
    this->nextNode = next;
    this->previousNode = prev;
}

//Destructor Nodo
Node:: ~Node(){
    delete data;
    delete nextNode;
    delete previousNode;
}

//Geter de datos de la lista
int Node::getData(){
    int num = *data;
    return num;
}

//Seter de datos de la lista
void Node::setData(int _data){
    this->data = &_data;
}

// Complejidad O(n)
//apartir de un index dado accede a un nodo deseado y actualiza con el dato dado
void LinkedList::update(int iter, int _data){
    Node* tmp;
    tmp = this->head;
    for (int i = 0; i < iter && tmp != NULL; i++)
    {
        tmp = tmp->nextNode;
    }
    if (tmp != NULL)
    {
        tmp->setData(_data);
    }
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
};

//Constructor Lista ligada
LinkedList::LinkedList(){
    this->head = NULL;
}

//Funcion insertar un nodo despues de otro nodo dado
// Complejidad O(1)
//apartir de un nodo dado inserta uno despues
Node* LinkedList::insertAfter(Node* beforeNode, int _data){
    Node *newNode = new Node();
    newNode->setData(_data);
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
Node* LinkedList::insertBefore(Node* afterNode, int _data){
    Node *newNode = new Node();
    newNode->setData(_data);    
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
    cout<<" NULL ";
}

//Busqueda de un elemento (por numero/dato)
//Regresa el indice en la lista
// Complejidad O(n)
//apartir de un dato dado recorre la lista hasta encontrar el numero y regresa el index
int LinkedList::search(int _data){
    Node* tmp;
    tmp = this->head;
    for (int i = 0; i < len; i++)
    {
        if (tmp->getData() == _data)
        {
            return i;
        }
        tmp = tmp->nextNode;
    }
    throw "No existe en lista";
}


int main(){
    LinkedList ll; 
    ll.fillList("lista.txt");
    ll.printList();
    cout<<"\nDeste: "<<ll[2].getData();
    cout<<"\nDeste: "<<ll.search(3);

    return 0;
}

