#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
    public:
    std::string month, day, hour, ip, reason;
    Node *nextNode;
    Node *previousNode;
    Node();
    Node(std::string&, std::string&, std::string&, std::string&, std::string&, Node*, Node*);
    std::string getData();
    void setData(std::string&, std::string&, std::string&, std::string&, std::string&);
    ~Node();
    friend std::ostream &operator <<(std::ostream& salida, const Node&);
    int dateIntCode();
};

#endif // NODE_H
