#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node();
    Node(int&);
    Node(int&, Node*, Node*);
    int getData();
    void setData(int&);
    ~Node();
};

#endif // NODE_H
