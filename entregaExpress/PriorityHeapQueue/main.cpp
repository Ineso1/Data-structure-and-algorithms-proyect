//Ines Alejandro Garcia Mosqueda A00834571
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Node{
    public:
        //Data Nodo
        int value;
        int priority;
        //Accesos
        Node* left;
        Node* right;
        Node* next;
        Node* previous;
        Node(){
            left=NULL;
            right=NULL;
            next=NULL;
            previous=NULL;
            priority=0;
            value=0;
        }
        Node(int value, int priority){
            left=NULL;
            right=NULL;
            next=NULL;
            previous=NULL;
            this -> value = value;
            this -> priority = priority;
        }
};

//Nodo Direccion
class NodeDir{
    public:
    //Ruta
    int index;
    int direction;
    //Enlace
    NodeDir* next = NULL; 
    NodeDir(int index, int direction){
        this -> index = index;
        this->direction = direction;
        next=NULL;
    }
    ~NodeDir(){
        //delete next;
    }
};

//Stack directorio
class Directory{
    public:
    NodeDir* head;
    int size;
    Directory(){
        head = NULL;
        size = -1;
    };
    ~Directory(){
        delete head;
    };
    void push(int index, int direction){
        size++;
        NodeDir* newNode = new NodeDir(index,direction);
        NodeDir* tmp = head;
        head = newNode;
        head->next = tmp;
    };
    NodeDir pop(){
        if (size >= 0)
        {
            NodeDir *tmp = head;
            head = head->next;
            size--;
            return *tmp;
        }
        return NodeDir(0,0);
    };
    NodeDir top(){
        if (size >= 0)
        {
            return *head;
        }
        return NodeDir(0,0);
    };
    bool empty(){
        if (size <= -1)
            return true;
        else
            return false;
        };
};

//Clase principal
class PriorityQueue
{
    int len;
    Node *head;
    Node *tail;
    private:
    //Busqueda de nodo padre para un nodo hijo O(logn)
    void searchChildFather(int index, Directory &directory){
        int fatherIndex, fatherDirection;
        if (index == 0){
            fatherIndex = 0;
            fatherDirection = 0;
            return;
        }
        else
        {
            double resDouble = (index-1)/2.0;
            int resInt = (index-1)/2;
            if (resDouble > resInt)
                fatherDirection = 1;
            
            else
                fatherDirection = -1;
            
            fatherIndex = resInt;
            directory.push(fatherIndex, fatherDirection);
            searchChildFather(fatherIndex, directory);
        }
    };
    //Intercambio de nodos O(1)
    void swap(Node* &node1, Node* &node2){
        int valueAux = node1->value;
        int priorityAux = node1->priority;
        node1->value = node2->value;
        node1->priority = node2->priority;
        node2->value = valueAux;
        node2->priority = priorityAux;
    }
    //A partir de un nodo hoja busca su ruta e intercambia los nodos padres que son mas grandes que el hijo O(logn)
    void elevate(Directory directory, Node* &node1, Node* &node2){
        if (directory.size < 0 || node1 == NULL)
        {
            return;
        }
        else
        {
            if (node1->value > node2->value)
            {
                swap(node1, node2);
            }
            Node* tmp = NULL;
            NodeDir NodeDirection = directory.pop();
            if (NodeDirection.direction == -1)
                tmp = node1->left;
            else if(NodeDirection.direction == 1)
                tmp = node1->right;
            return elevate(directory, tmp, node2);
        }
    }

    //Crea lista de un nodo para elevar el nodo hijo dentro del Heap O(logn)
    void bubbleUp(int index, Node* &node){
        Node* tmp;
        Directory fathersDir;
        searchChildFather(index, fathersDir);
        elevate(fathersDir, head, tail);
    }

    //Desde un nodo padre intercambia valores con el hijo en caso de se mayor que el hijo O(logn)
    void bubbleDown(Node* node){
        if (node->left == NULL)
        {
            return;
        }
        else if (node->left->value > node->value && node->right == NULL)
        {
            swap(node, node->left);
        }
        else if (node->left->value < node->value && node->right == NULL){
            return;
        }
        else if (node->left->value > node->value && node->right->value > node->value)
        {
            return;
        }
        else
        {
            if (node->left->value < node->right->value)
            {   
                swap(node, node->left);
                bubbleDown(node->left);
            }
            else if (node->left->value > node->right->value)
            {
                swap(node, node->right);
                bubbleDown(node->right);
            }
            bubbleDown(node->left);
            return;
        }
    }
    //Accede al padre de un nodo apartir del directorio creado O(logn)
    Node* accesNode(Node* node, Directory &directory){
        if (directory.size < 1 || node == NULL)
        {
            return node;
        }
        else
        {
            Node* tmp = NULL;
            NodeDir NodeDirection = directory.pop();
            if (NodeDirection.direction == -1)
                tmp = node->left;
            else if(NodeDirection.direction == 1)
                tmp = node->right;
            return accesNode(tmp, directory);
        }
    }
    public:
    PriorityQueue(){
        len = -1;
        head = NULL;
        tail = head;
    }
    //Anade un nodo a la estructra conservando propiedades O(logn)
    void push(int value, int priority){
    Node* newNode = new Node(value, priority);
    if (isEmpty())
    {
        tail = newNode;
        head = tail;
        len++;
        
    }
    else
    {   
        len++;
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;

        Node* tmp;
        Directory fathersDir;
        searchChildFather(len, fathersDir);
        tmp = accesNode(head, fathersDir);
        if (tmp->left == NULL)
        {
            tmp->left = newNode;
        }
        else if (tmp->right == NULL)
        {   
            tmp->right = newNode;
        }
        else
        {
            cout<<"Algo pasa aqui";
        }
        bubbleUp(len, tail);
    }
    };
    //Borra un nodo de la estructura conservando estructura O(logn)
    void pop(int index){
        Node* tmp;
        Directory fathersDir;
        searchChildFather(index, fathersDir);
        tmp = accesNode(head, fathersDir);
        swap(tmp, tail);
        bubbleDown(tmp);
        tmp = tail->previous;
        delete tail;
        tail = tmp;
        tail->next=NULL;
        len--;
    };

    //Regresa el nodo mas chicode la estructura O(1)
    Node top(){
        if(isEmpty())
        {
            throw invalid_argument("heap vacio");
        }
        return *head;
    };

    bool isEmpty(){
    if (len == -1)
        return true;
    else
        return false;
    };

    int size(){
        return len+1;
    };

    //lLenado de estructura O(nlogn)
    void fillQueue(string fileName){
        ifstream file;
        file.open(fileName);
        int value, priority;
        while (file >> value >> priority)
        {
            push(value, priority);
        }
        file.close();
    };

    void print(){
        Node* tmp = head;
        while (tmp != NULL)
        {
            cout<<" ( " << tmp->value << ", " << tmp->priority << " )\t";
            tmp = tmp->next;
        }
    }
};

int main(){
    PriorityQueue pq;
    cout<<"\nLLenado de estructura "<<endl;
    pq.fillQueue("test2.txt");
    pq.print();
    cout<<"\nEstructura con tamano de "<< pq.size() << " elementos\n" <<endl;
    cout<<"\npop de dato en indice 5 "<<endl;
    pq.pop(5);
    cout<<endl;
    pq.print();
    cout<<"\npush de dato con prioridad 7 y data 5 "<<endl;
    pq.push(7, 5);
    cout<<endl;
    pq.print();
    cout<<"\nPrioridad del nodo en cabeza "<<pq.top().value;
    return 0;
}