#ifndef BST_H
#define BST_H
#include <iostream>
#include "Node.h"

class BST{
        Node* head;
    private:
        void insertNode(Node*&, int&);  //Insersion de nodo en un nodo // jala
        void deleteNode(Node*&, int&); //Algoritmo de eliminacion de un nodo // Checar para cuando tienen un hijo
        void PreOrder(Node*&);  //Ordenamiento PreOrder  // jala
        void PostOrder(Node*&);  //ORdenamiento PostOrder // jala
        void InOrder(Node*&);  //Ordenamiento InOrder // jala
        void SubstituteToMin(Node*&, Node*&);
        
    public:
        BST();  // jala
        BST(int);  // jala
        ~BST(); // jala
        void llenarBST(std::string);  // jala
        void searchNode(int&);  //Busqueda de un nodo dentro del arbol
        void insert(int&); 
        void InOrder();  // Jala
        void PreOrder(); // Jala
        void PostOrder(); // Jala
        void BFT(); // Jala
        void deleteNode(int&);  //Jala
        void deleteTree(Node*&); 
};

#endif // BST_H
