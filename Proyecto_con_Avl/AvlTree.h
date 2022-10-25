#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include "Node.h"

class AvlTree{
    private:
    Node* head;
    void insertNode();
    void deleteNode();
    void PreOrder();
    void InOrder();
    void PostOrder();
    void BFT();

    public:
    AvlTree();
    void fillTree();
    void insertNode();
};

#endif // AVLTREE_H
