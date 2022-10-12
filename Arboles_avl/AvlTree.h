#ifndef AVLTREE
#define AVLTREE
#include <iostream>
#include "Node.h"

class AvlTree{
        Node* head;
    private:
        void Preorder(Node*);
        void Postorder(Node*);
        void InOrder(Node*);
        void insertNode(int&, Node*);
        void deleteNode(int&, Node*&);
    public:
        AvlTree();
        ~AvlTree();
        void print();
        void searchNode(int&);
        void insert(int&);
        void InOrder();
        void PreOrder();
        void PostOrder();
        void BFT();
        void deleteNode(int&);
        void SubstituteToMin(Node*&, Node*&);
        void deleteTree();
};

#endif // AVLTREE
