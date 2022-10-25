#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node();
    Node(int&, Node*, Node*);
    std::string getData();
    void setData(int);
    ~Node();
    friend std::ostream &operator <<(std::ostream& salida, const Node&);
};

#endif // NODE_H
