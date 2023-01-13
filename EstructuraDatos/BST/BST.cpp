#include "BST.h"
#include <fstream>
#include <queue>


BST::BST(){
    Node *head = NULL;
}

BST::BST(int data){
    head = new Node(data);
}

BST::~BST(){
    deleteTree(head);
}

void BST::insertNode(Node* &nodo, int &data){
    if (nodo == NULL)
    {
        nodo = new Node(data);
    }
    else{
        if(nodo->data > data){
            insertNode(nodo->left, data);
        }
        else if(nodo->data < data){
            insertNode(nodo->right, data);
        }
        else{
            std::cout << data << " Repetido ";
        }
    }
}

void BST::deleteNode(Node* &nodo, int& data){
    if (nodo != NULL)
    {
        if (data < nodo->data)
        {
            deleteNode(nodo->left, data);
        }
        else if(data > nodo->data){
            deleteNode(nodo->right, data);
        }
        else
        {
            Node* auxNodo = nodo;

            if (auxNodo->right == NULL)
            {
                nodo = auxNodo->left;
            }
            if (auxNodo->left == NULL)
            {
                nodo = auxNodo->right;
            }
            if (auxNodo->left != NULL && auxNodo->right != NULL )
            {
                SubstituteToMin(nodo->right, auxNodo);
            }
            std::cout<<"Se borro correctamente";
            delete auxNodo;
        }
        
    }
}

void BST::SubstituteToMin(Node* &nodo, Node* &auxNodo){
    if(nodo->left != NULL){
        SubstituteToMin(nodo->left, auxNodo);
    }
    else
    {
        auxNodo -> data = nodo -> data;
        auxNodo = nodo;
        nodo = nodo -> right;
    }
    
}

void BST::PostOrder(Node* &nodo){
    if (nodo != NULL)
    {
        PostOrder(nodo->left);
        PostOrder(nodo->right);
        std::cout<< " " << nodo->data;
    }
}

void BST::PreOrder(Node* &nodo){
    if (nodo != NULL)
    {
        std::cout<< " " << nodo->data;
        PreOrder(nodo->left);
        PreOrder(nodo->right);
    }
}

void BST::InOrder(Node* &nodo){
    if(nodo != NULL)
    {
        InOrder(nodo->left);
        std::cout << " " <<nodo->data;
        InOrder(nodo->right);
    }
}

/*..........................................................*/


void BST::searchNode(int& x){
    /**/
}

void BST::llenarBST(std::string fileName){
    std::ifstream file;
    file.open(fileName);
    int data;
    if(file >> data){
        head = new Node(data);
            while (file >> data)
            {
                insertNode(head, data);
            }
    }
}

void BST::insert(int& data){
    insertNode(head, data);
}

void BST::InOrder(){
    InOrder(head);
}

void BST::PreOrder(){
    PreOrder(head);
}

void BST::PostOrder(){
    PostOrder(head);
}

void BST::deleteNode(int &data){
    deleteNode(head, data);
}

void BST::BFT(){
    if (head != NULL)
    {
        std::queue<Node*> elements;
        elements.push(head);
        Node* auxNode;
        while (!elements.empty())
        {
            elements.push(NULL);
            auxNode = elements.front();
            while (auxNode !=NULL)
            {
                std::cout<<auxNode->data<<" ";
                if (auxNode->left != NULL)
                {
                    elements.push(auxNode->left);
                }
                if (auxNode->right != NULL)
                {
                    elements.push(auxNode->right);
                }
                elements.pop();
                auxNode = elements.front();
            }
            elements.pop();
            std::cout<<std::endl;
        }
        
    }
}

void BST::deleteTree(Node* &nodo){
    if (nodo != NULL)
    {
        PostOrder(nodo->left);
        delete nodo;
        PostOrder(nodo->right);
        delete nodo;
    }
}