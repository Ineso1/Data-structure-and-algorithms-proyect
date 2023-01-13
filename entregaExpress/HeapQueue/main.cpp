#include <iostream>
#include <fstream>
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


class PriorityQueue
{
    int len;
    Node *head;
    Node *tail;
    private:
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
        cout<<tmp->value;
    }
    };

    void pop();
    Node top();
    bool isEmpty(){
    if (len == -1)
        return true;
    else
        return false;
    };

    /*Funcion q no he hecho*/
    int size();

    //Lenado de estructura
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

};

int main(){
    PriorityQueue pq;
    pq.fillQueue("test.txt");
    return 0;
}