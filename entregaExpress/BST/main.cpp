//Ines Alejandro Garcia Mosqueda
#include <iostream>
#include <fstream>
#include <queue>

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

//Constructor Nodo
Node::Node(){
    data = 0;
    left = NULL;
    right = NULL;
}

Node::Node(int &data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

//Sobrecarga nodo
Node::Node(int &data, Node* left, Node* right) {
    this->data = data;
    this->left = left;
    this->right = right;
}

//Destructor Nodo
Node::~Node(){
    delete left;
    delete right;
}

//Getter de datos de la lista
int Node::getData(){
    return this->data;
}

//Seter de datos de la lista
void Node::setData(int &data){
    this->data = data;
}

class BST{
        Node* head;
    private:
        void insertNode(Node*&, int&);  //Insersion de nodo en un nodo // jala
        void deleteNode(Node*&, int&); //Algoritmo de eliminacion de un nodo
        void PreOrder(Node*&);  //Ordenamiento PreOrder  // jala
        void PostOrder(Node*&);  //ORdenamiento PostOrder // jala
        void InOrder(Node*&);  //Ordenamiento InOrder // jala
        void SubstituteToMin(Node*&, Node*&);
        int height(Node*);
        void ancestors(Node*,int);
        int whatLevelAmI(Node*,int);

        
    public:
        BST(){ Node *head = NULL; };  // jala
        BST(int data){ head = new Node(data); };  // jala
        ~BST(){ deleteTree(head); }; // jala
        void fillBST(std::string);  // jala
        void searchNode(int&);  //Busqueda de un nodo dentro del arbol
        void insert(int&); //Jala
        void InOrder();  // Jala
        void PreOrder(); // Jala
        void PostOrder(); // Jala
        void BFT(); // Jala
        void deleteNode(int&);  //Jala
        void deleteTree(Node*&); //Jala
        void visit();
        int height();
        void ancestors(int);
        int whatLevelAmI(int);
};

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
            std::cout << data << " Repetido " <<"\n";
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

void BST::searchNode(int& x){
    /**/
}

void BST::fillBST(std::string fileName){
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

void BST::visit(){
    std::cout<<"\nSecuencia que quieres realizar\n1. InOrder\n2. PostOrder\n3. PreOrder\n";
    int op;
    std::cin>>op;
    if (op==1)
    {
        InOrder();
    }
    else if (op==2)
    {
        PostOrder();
    }
    else if (op==3)
    {
        PreOrder();
    }
    else{
        std::cout<<"\nOpcion no encontrada\n";
    }    
}

int BST::height(){
    return height(head);
}

void BST::ancestors(Node* node, int value){
    if (node == NULL || node->data == value)
    {
        return;
    }
    else{
        std::cout<< node->data <<" ";
        if (node->data < value)
            ancestors(node->right, value);
        else
            ancestors(node->left, value);
        return;
    }
    
}

int BST::height(Node* node){
    if (node == NULL){
        return -1;
    }
    else{
        int derecha = 0, izquierda = 0; 
        derecha = height(node->right) + 1;
        izquierda = height(node->left) + 1;
        if (derecha > izquierda)
            return derecha;
        else
            return izquierda;
    }
}

void BST::ancestors(int data){
        ancestors(head, data);
}

int BST::whatLevelAmI(Node* node, int value){
    if (node==NULL)
    {
        throw -1;
    }
    
    if (node->data == value)
    {
        return 1;
    }
    else{
        if (node->data < value)
            return whatLevelAmI(node->right, value) +1;
        else
            return whatLevelAmI(node->left, value) +1;
    }
}

int BST::whatLevelAmI(int value){
    return whatLevelAmI(head, value);
}

int main(){
    BST tree;
    tree.fillBST("test.txt");
    std::cout<<"\nSecuencia InOrder";
    tree.InOrder();
    std::cout<<"\nSecuencia PostOrder";
    tree.PostOrder();
    std::cout<<"\nSecuencia PreOrder";
    tree.PreOrder();
    std::cout<<"\nSecuencia BFT\n";
    tree.BFT();
    int n = 8;
    std::cout<<"\nEvaluacion del numero "<< n <<std::endl;
    std::cout<<"Ancestros: ";
    tree.ancestors(n);
    std::cout<<std::endl;
    std::cout<<"Nivel de este numero: " << tree.whatLevelAmI(n);
    std::cout<<std::endl;
    int altura = tree.height();
    std::cout<<"Altura: "<< altura <<" niveles\n\n";
    


    return 0;
}