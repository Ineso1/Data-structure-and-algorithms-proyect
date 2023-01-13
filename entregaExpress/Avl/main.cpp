//Ines Alejandro Garcia Mosqueda A00834571
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        int factor;
        Node* left;
        Node* right;
        Node(){
            this->data = 0;
            this->factor = 0;
            this->left == NULL;
            this->right = NULL;
        };
        Node(int data){
            this->data = data;
            this->factor = 0;
            this->left = NULL;
            this->right = NULL;
        };
        Node(int data, Node* left, Node* right){
            this->data = data;
            this->left = left;
            this->right = right;
            this->factor = 0;
            if (left != NULL)
                this->factor -= 1; 
            if(right != NULL)
                this->factor += 1;
        };
        ~Node(){
            delete left;
            delete right;
        }; //Destructor de Nodo
        void setData(int data){
            this->data = data;
        };
        int getData(){
            return this->data;
        };
};

class AvlTree{
    Node* head;
    int len;
    private:
        void insertNode(Node*&, int); // O(logn)
        void deleteNode(Node*&, int&); // O(logn)
        void PreOrder(Node*); // O(n)
        void InOrder(Node*); // O(n)
        void PostOrder(Node*); // O(n)
        void SubstituteToMin(Node*&, Node*&); // O(logn)
        int updateHeight(Node*); // O(logn)
        void updateHeight(){ updateHeight(head); }; // O(logn)
        void rightRotation(Node*&); // O(1)
        void leftRotation(Node*&); // O(1)
        void leftRightRotation(Node*&); // O(1)
        void rightLeftRotation(Node*&); // O(1)
        void balance(Node*&); // O(1)
        void find(Node*, int, bool&); // O(logn)
        

    public:
        AvlTree(){
            head = NULL;
            len = 0;
        };
        void insertNode(int data){ insertNode(head, data); };
        void deleteNode(int data){ deleteNode(head, data); };
        void PreOrder(){ PreOrder(head); };
        void InOrder(){ InOrder(head); };
        void PostOrder(){ PostOrder(head); };
        void BFT();
        void fillAvl(string);
        bool find(int);
        void print();
        int size(){ return len; };
};

void AvlTree::insertNode(Node* &node, int data){
    if (node == NULL){
            Node* newNode = new Node(data);
            node = newNode;
            len ++;
            updateHeight();
        }
    else{
        if (data > node->getData())
            insertNode(node->right, data);
        else if(data < node->getData())
            insertNode(node->left,data);
        else
            cout<< "\n-->" << data << "  Dato repetido";
        balance(node);
    }
}

void AvlTree::deleteNode(Node* &node, int& data){
    if (node != NULL)
    {
        if (data < node->data){
            deleteNode(node->left, data);
        }
        else if(data > node->data){
            deleteNode(node->right, data);
        }
        else
        {
            Node* auxNodo = node;

            if (auxNodo->right == NULL){
                node = auxNodo->left;
            }
            if (auxNodo->left == NULL){
                node = auxNodo->right;
            }
            if (auxNodo->left != NULL && auxNodo->right != NULL )
                SubstituteToMin(node->right, auxNodo);
            std::cout<<"Se borro correctamente";
            delete auxNodo;
            len--;
            updateHeight(head);
        }
        if (node!=NULL)
            balance(node);
    }
}

void AvlTree::PreOrder(Node* node){
    if (node == NULL)
        return;
    else{
        PreOrder(node->left);
        PreOrder(node->right);
        cout << node->getData() << ", ";
    }
}

void AvlTree::InOrder(Node* node){
    if (node == NULL)
        return;
    else{
        InOrder(node->left);
        cout << node->getData() << ", ";
        InOrder(node->right);
    }
}

void AvlTree::PostOrder(Node* node){
    if (node == NULL)
        return;
    else{
        cout << node->getData() << ", ";
        PostOrder(node->left);
        PostOrder(node->right);
    }
}

void AvlTree::BFT(){
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
                    elements.push(auxNode->left);
                if (auxNode->right != NULL)
                    elements.push(auxNode->right);
                elements.pop();
                auxNode = elements.front();
            }
            elements.pop();
            std::cout<<std::endl;
        }
    }
}

void AvlTree::fillAvl(string fileName){
    ifstream file;
    int data;
    file.open(fileName);
    while (file >> data)
    {
        insertNode(data);
    }
}

void AvlTree::SubstituteToMin(Node* &nodo, Node* &auxNodo){
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

int AvlTree::updateHeight(Node* node){
    if (node == NULL)
        return -1;
    else{
        int rightHeight = 0, leftHeight = 0;
        rightHeight = updateHeight(node->right) + 1;
        leftHeight = updateHeight(node->left) + 1;
        node->factor = leftHeight  - rightHeight;
        if (rightHeight > leftHeight)
            return rightHeight;
        else
            return leftHeight;
    }
}

void AvlTree::rightRotation(Node* &node) {
    Node* auxLeft;
    Node* auxRightAux;
    auxLeft = node->left;
    auxRightAux = auxLeft->right;
    auxLeft->right = node;
    auxLeft->right->left = auxRightAux;
    node = auxLeft;
    //cout<<"RightRotation\n";
}
void AvlTree::leftRotation(Node* &node) {
    Node* auxRight;
    Node* auxLeftAux;
    auxRight = node->right;
    auxLeftAux = auxRight->left;
    auxRight->left = node;
    auxRight->left->right = auxLeftAux;
    node = auxRight;
    //cout<<"LeftRotation\n";
}
void AvlTree::leftRightRotation(Node* &node) {
    Node* auxLeft;
    Node* auxRightAux;
    auxLeft = node->left;
    auxRightAux = auxLeft->right;
    auxLeft->right = auxRightAux->left;
    auxRightAux->left = auxLeft;
    node->left = auxRightAux;
    //cout<<"LeftRightRotation\n";
    rightRotation(node);
}
void AvlTree::rightLeftRotation(Node* &node) {
    Node* auxRight;
    Node* auxLeftAux;
    auxRight = node->right;
    auxLeftAux = auxRight->left;
    auxRight->left = auxLeftAux->right;
    auxLeftAux->right = auxRight;
    node->right = auxLeftAux; 
    //cout<<"RightLeftRotation\n";
    leftRotation(node);
}

void AvlTree::balance(Node* &node){
    if (node->factor > 1) {
        if (node->left->factor > 0)
            rightRotation(node);
            //Right rotation
        else
            leftRightRotation(node);
            //left right rotation
        updateHeight(node);
    } 
    else if (node->factor < -1) {
        if (node->right->factor > 0)
            rightLeftRotation(node);
            //Right left rotation
        else
            leftRotation(node);
            //left rotation
        updateHeight(node);
   }
}

void AvlTree::find(Node* node, int data, bool &search){
    if(node != NULL){
        if (data > node->data)
            find(node->right, data, search);
        else if (data < node->data)
            find(node->left, data, search);
        else
            search = true;
        }        
    }

bool AvlTree::find(int data){
    bool resSearch = false;
    find(head, data, resSearch);
    return resSearch;
}

void AvlTree::print(){
    cout<<"\n\nDatos del arbol en orden ascendente"<<endl;
    InOrder();
    cout<<"\n\nReprsentacion por niveles"<<endl;
    BFT();
    cout<<endl;
}

int main(){
    AvlTree avl;
    avl.fillAvl("test.txt");
    cout<<"\n\nEn el arbol hay: "<< avl.size()<< " Elementos" <<endl;
    avl.print();
    cout <<"Busqueda numero 10: "<<avl.find(10)<<endl;
    cout<<"\nBorrando 4"<<endl;
    avl.deleteNode(4);
    cout<<"\nBorrando 10"<<endl;
    avl.deleteNode(10);
    cout<<"\n\nEn el arbol hay: "<< avl.size()<< " Elementos" <<endl;
    avl.print();
    cout <<"Busqueda numero 10: "<<avl.find(10)<<endl;
    return 0;
}