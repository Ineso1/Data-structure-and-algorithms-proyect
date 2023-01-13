#include "Node.h"

//Constructor Nodo
Node::Node(){
    data = 0;
    left = NULL;
    right = NULL;
}

Node::Node(int &data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

//Sobrecarga nodo
Node::Node(int &data, Node* left, Node* right) {
    this->data = data;
    this->left = left;
    this->right = right;
}

//Destructor Nodo
Node::~Node(){
    delete left;
    delete right;
}

//Getter de datos de la lista
int Node::getData(){
    return this->data;
}

//Seter de datos de la lista
void Node::setData(int &data){
    this->data = data;
}