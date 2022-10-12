#include "Node.h"

//Constructor Nodo
Node::Node(){
    data = 0;
    left = nullptr;
    right = nullptr;
}

//Sobrecarga nodo
Node::Node(int data, Node* left, Node* right) {
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
std::string Node::getData(){
    std::string res = "" + this->data;
    return res;
}

//Seter de datos de la lista
void Node::setData(int data){
    this->data = data;
}

//Sobrecarga para ostream de nodo
std::ostream& operator <<(std::ostream& os, const Node& node){
    os << node.data + " ";
    return os;
}
