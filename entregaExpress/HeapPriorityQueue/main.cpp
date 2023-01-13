#include <iostream>
#include <fstream>
using namespace std;

class Node{
    public:
        //Data Nodo
        int value;
        int priority;
        //Accesos
        Node* left;
        Node* right;
        Node* next;
        Node* previous;
        Node(){
            left=NULL;
            right=NULL;
            next=NULL;
            previous=NULL;
            priority=0;
            value=0;
        }
        Node(int value, int priority){
            left=NULL;
            right=NULL;
            next=NULL;
            previous=NULL;
            this -> value = value;
            this -> priority = priority;
        }
};