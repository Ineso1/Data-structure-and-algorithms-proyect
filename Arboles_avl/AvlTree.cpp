#include "AvlTree.h"

AvlTree::AvlTree(){
    /**/
}

AvlTree::~AvlTree(){
    /**/
}

void AvlTree::Postorder(Node*){
    /**/
}

void AvlTree::Preorder(Node*){
    /**/
}

void AvlTree::InOrder(Node* current){
    InOrder(current->left);
    std::cout<<current->data<<" ";
    InOrder(current->right);
}

void AvlTree::insertNode(int& data, Node* current){
    if (current != NULL)
    {
        Node* newNode = new Node;
        newNode->setData(data);
    }
    else{
        if (data < current->data)
        {
            insertNode(data, current->left);
        }
        else if (data > current->data)
        {
            insertNode(data, current->right);
        }
        else{
            std::cout << " Repetido ";
        }
    }
}

void AvlTree::deleteNode(int&, Node*&){
    /**/
}

void AvlTree::print(){
    /**/
}

void AvlTree::searchNode(int&){
    /**/
}

void AvlTree::insert(int& data){
    insertNode(data, head);
}

void AvlTree::InOrder(){
    InOrder(head);
}

void AvlTree::PreOrder(){
    /**/
}

void AvlTree::PostOrder(){
    /**/
}

void AvlTree::BFT(){
    /**/
}

void AvlTree::deleteNode(int& value){
    /**/
}


void AvlTree::SubstituteToMin(Node*& a, Node*& b){
    /**/
}

void AvlTree::deleteTree(){
    /**/
}
