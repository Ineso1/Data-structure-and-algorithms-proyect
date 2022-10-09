#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include "Node.h"

//Lista Ligada
class LinkedList{
    public:
        LinkedList();
        Node* head;
        int len = 0;
        Node* insertBefore(Node*, std::string, std::string, std::string, std::string, std::string);
        Node* insertAfter(Node*, std::string, std::string, std::string, std::string, std::string);
        Node* insertAfter(Node*, Node*);
        void fillList(std::string);
        void printList();
        int search(std::string, std::string, std::string, std::string, std::string);
        Node &operator[](int);
        void update(int, std::string, std::string, std::string, std::string, std::string);
        void deleteNode(int);
        int sortNodeDate(Node*&);
        int sortNodeIp(Node*&);
        void saveSortedList();
        void findRangeIp(std::string, std::string);
        
};

#endif // LINKEDLIST
