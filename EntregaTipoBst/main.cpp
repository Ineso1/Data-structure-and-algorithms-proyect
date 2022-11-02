//Ines Alejandro Garcia Mosqueda A00834571
//Jesus Fong Ruiz A01254062
//https://github.com/Ineso1/Data-structure-and-algorithms-proyect
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

//Clase basica para almacenamiento de informacion de peticion
class Node{
    public:
    string month, day, hour, ip, reason;
    int numAccess;
    Node *left;
    Node *right;
    Node(){     //Constructor vacio
        numAccess = 0;
        month = "";
        day = "";
        hour = "";
        ip = "";
        reason = "";
        left = NULL;
        right = NULL;
    }
    Node(string &month, string &day, string &hour, string &ip, string &reason){      //Constructor de todos los parametros
        this->numAccess = 1; 
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->reason = reason;
        this->left = NULL;
        this->right = NULL;
    }
    Node(string &month, string &day, string &hour, string &ip, string &reason, Node* left, Node* right){      //Constructor de todos los parametros
        this->numAccess = 1;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->reason = reason;
        this->left = left;
        this->right = right;
    }
    string getData(){       //Return de fecha en formato "mes dia hora:minuto:segundo.milisegundos ip(XXX.XXX.XXX:XXXX) razon"
        string ipNoPort = ip;
        ipNoPort.erase(ipNoPort.length()-5);
        string res = this->month + " " + this->day + " " + this->hour + " " + ipNoPort + " " + this->reason;
        return res;
    }
    void setData(string &month, string &day, string &hour, string &ip, string &reason){     //Reescritura de fecha
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->reason = reason;
    }
    void addAttempt(){ numAccess++; }
    ~Node(){
        delete left;
        delete right;
    }
    int getAttempts(){ return numAccess; }
    string getAccessIp(){
        return ip + " ---- " + to_string(numAccess);
    }
    int dateIntCode(){  //Codificacion de fecha
        try
        {
            std::map<std::string, std::string> monthNum = {
                {"Jun", "6"},
                {"Jul", "7"},
                {"Aug", "8"},
                {"Sep", "9"},
                {"Oct", "10"},
                {"Nov", "11"},
                {"Dic", "12"}
            };
            std::string result;
            if (day.length() == 1)
            {
                day = "0" + day;
            }

            result = monthNum[month]+day 
            +hour[0]+hour[1]
            +hour[3]+hour[4]
            +hour[6]+hour[7];

            return stoi(result);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }
    unsigned long long ipIntCode(){  //Codificacion ip
        try
        {
            std::string result = "";
            int dig = 0;
            int sep = 0;
            std::string cuarteto = "";
            for (int i = 0; i < ip.length(); i++)
            {   
                if(ip[i] != '.' && ip[i] != ':')
                {
                    cuarteto += ip[i];
                    dig++;
                }
                else{
                    if (ip[i] == ':')
                    break;
                    while (dig<3)
                    {
                        cuarteto = "0" + cuarteto;
                        dig++;
                    }
                    dig = 0;
                    result += cuarteto;
                    cuarteto = "";
                }
            }
            result+=cuarteto;
            return std::stoull(result);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << ": Algun error por aqui" << '\n';
            return -1;
        }
    }
};

// Estructura de datos para almacenar el valor maximo en el top de la lista 
class Heap{
    int len, maxLen;
    Node** accessList;    
    private:
        void swap(int&, int&);  //O(1)
        void bubbleDown(int&);  //O(logn)
    public:
        Heap(int num){ 
            len = -1;
            maxLen = num;
            accessList = new Node*[num+1]; 
            };
        void push(Node*&);  //O(logn)
        Node* pop();    //O(logn)
        void save(string);  //O(nlogn)
        void print();   //O(n)
};

void Heap::push(Node*& node){
    if (len > maxLen)
        throw invalid_argument("Heap overflow");
    else{
        len++;
        accessList[len] = node;
    }
    int father = (len-1)/2, i = len;
    while (accessList[father]->getAttempts() < accessList[i]->getAttempts())
    {
        swap(father, i);
        i = father;
        father = (i-1)/2;
    }
}

void Heap::bubbleDown(int& father){
    if (father < len)
    {
        int leftChild = (father*2) + 1;
        int rightChild = (father*2) + 2;
        int max = father;
        if (leftChild < len && accessList[leftChild]->getAttempts() > accessList[father]->getAttempts())
            max = leftChild;
        if (rightChild < len && accessList[rightChild]->getAttempts() > accessList[max]->getAttempts())
            max = rightChild;    
        if(max != father){
            swap(father, max);
            bubbleDown(max);
        }
    }
}

Node* Heap::pop(){
    int top = 0;
    Node* tmp = accessList[0];
    swap(top, len);
    len--;
    int father = 0;
    bubbleDown(father);
    return tmp;    
}

void Heap::swap(int& father, int& child){
    Node* aux = accessList[father];
    accessList[father] = accessList[child];
    accessList[child] = aux;
}

void Heap::print(){
    for (int i = 0; i < len; i++)
    {   
        string ip = accessList[i]->ip;
        ip.erase(ip.length()-5);
        cout << ip << " - " << accessList[i]->numAccess << endl;
    }
};

void Heap::save(string fileName){
    ofstream file;
    file.open(fileName);
    while (len>=0)
    {
        Node* tmp = pop();
        file << tmp->getAccessIp() << "\n";
    }
    file.close();
}

//Estructura de datos para almacenamiento de todos los datos dentro de la bitacora de peticiones
class BST{
    Node* head;
    int orderType = 0;
    int len;
    private:
        void insertNode(Node*&, Node*&); //Insercion de nodo dentro de la estructura    //O(logn)
        int sortType(Node*&, Node*&); //Dependiendo el tipo de ordenamiento se requiera (1 por Ip, 2 por Fecha) //O(1)
        void deleteNode(Node*&, string&, string&, string&, string&, string&);   //O(logn)
        void PreOrder(Node*&); //Imprime en preOrden    //O(n)
        void InOrder(Node*&); //Imprime en orden    //O(n)
        void saveInOrder(Node*&, ofstream&); //Guarda los datos del arbol de forma ascendente dentro un archivo //O(nlogn)
        void PostOrder(Node*&); // Imprime en postOrder //O(n)
        void SubstituteToMin(Node*&, Node*&); // Encuentra el minimo despues de un nodo //O(logn)
        void searchNode(Node*&, string&, string&); //Busqueda de un nodo en especifico  //O(logn)
        void fillHeap(Node*,Heap&);  //Con los datos del arbol llena una estructura Heap    //O(nlogn)
        //void deleteTree(Node*&);  //O(n)

    public:
        BST(){  //Constructor default
            Node* head = NULL;
            len = 0;
         };  
        //~BST(){ deleteTree(head); };
        void fillBST(std::string, int); //Llenado de arbol binario //O(nlogn)
        void insert(string&, string&, string&, string&, string&); //inserta un nodo //O(logn)
        void InOrder(){ InOrder(head); }; //Imprime en orden    //O(n)
        void PreOrder(){ PreOrder(head); }; //Imprime preOrder  //O(n)
        void PostOrder(){ PostOrder(head); }; //Imprime posOrder    //O(n)
        void deleteNode(string&, string&, string&, string&, string&); //Borra un nodo en especifico //O(logn)
        void searchRange(string&, string&); //Busca por rango   //O(nlogn)
        int size(){ return len; }; //Retorna tamano de datos dentro del arbol   //O(nlogn)
        void topAccess(); //Obtiene un archivo con las Ip ordenadas de acuerdo a la cantidad de accesos denegados   //O(nlogn)
        void save(string); //O(n)
        //void save(string fileName){ save(fileName); }; //Guarda ordenamiento de datos de acuerdo a la condicion de ordenamiento
};

int BST::sortType(Node*&node, Node*&newNode){
    if (orderType == 1)
    {   
        unsigned long long nodeCode = (node->ipIntCode()); 
        unsigned long long newNodeCode = (newNode->ipIntCode());
        if (nodeCode > newNodeCode)
            return 1;
        else if (nodeCode < newNodeCode)
            return -1;
        node->addAttempt();
        return 0;
    }
    else if (orderType == 2){
        int nodeCode = node->dateIntCode();
        int newNodeCode = newNode->dateIntCode();
        if (nodeCode > newNodeCode)
            return 1;
        else if (nodeCode < newNodeCode)
            return -1;
        node->addAttempt();
        return 0;
    }
    throw invalid_argument("Opcion de ordenamiento inexistente");
}

void BST::insertNode(Node* &node, Node* &newNode){
    if (node == NULL)
    {
        node = newNode;
        len++;
    }
    else{
        int step = sortType(node, newNode);
        if(step == 1){
            insertNode(node->left, newNode);
        }
        else if(step == -1){
            insertNode(node->right, newNode);
        }
        else{
            cout << newNode->getData() << " Repetido " <<"\n";
        }
    }
}

void BST::PreOrder(Node* &node){
    if (node != NULL)
    {
        std::cout<< " " << node->getData();
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

void BST::InOrder(Node* &node){
    if(node != NULL)
    {
        InOrder(node->left);
        cout << " " << node->getData() << endl;
        InOrder(node->right);
    }
}

void BST::saveInOrder(Node* &node, ofstream& file){
    if(node != NULL)
    {
        saveInOrder(node->left, file);
        file << node->month << " " 
        << node->day << " " 
        << node->hour << " " 
        << node->ip 
        << node->reason <<"\n";
        saveInOrder(node->right, file);
    }
}

void BST::PostOrder(Node* &node){
    if (node != NULL)
    {
        PostOrder(node->left);
        PostOrder(node->right);
        std::cout<< " " << node->getData();
    }
}

void BST::fillBST(std::string fileName, int condition){
    std::ifstream file;
    head = NULL;
    orderType = condition;
    len = 0;
    file.open(fileName);
    string month, day, hour, ip, reason;
    try{
    while (file >> month>> day>> hour>> ip)
        {
            getline(file, reason);
            Node* newNode = new Node(month, day, hour, ip, reason);
            insertNode(head, newNode);
        }
    }
    catch(invalid_argument e){
        cerr << e.what() << endl;
    }
}

void BST::fillHeap(Node* node, Heap& heap){
    if (node != NULL)
    {
        fillHeap(node->left, heap);
        heap.push(node);
        fillHeap(node->right, heap);
    }
}

void BST::save(string fileName){
    ofstream file;
    file.open(fileName);
    saveInOrder(head, file);
    file.close();
}

void BST::topAccess(){
    Heap heap(len);
    fillHeap(head, heap);
    heap.save("TopAccess.txt");
}

void FiveTopAccess(){
    ifstream file;
    file.open("TopAccess.txt");
    string row;
    cout<<"Top de accesos denegados dentro del sistema:"<<endl;
    for (int i = 0; i < 5; i++)
    {
        getline(file, row);
        cout << row << endl;
    }
}

int main(){
    //Instancia de objeto BST
    BST listadoInformacion;
    //Llenado de estructura BST por Fecha de intento de acceso O(nlogn)
    listadoInformacion.fillBST("bitacoraHeap.txt", 2);
    //Guardado de la estructura O(n)
    listadoInformacion.save("sortedByDate.txt");
    //Llenado de estructura BST por Ip O(nlogn)
    listadoInformacion.fillBST("bitacoraHeap.txt", 1);
    //Guardado de la estructura O(n)
    listadoInformacion.save("sortedByIp.txt");
    cout<<endl;
    cout<< "Elementos registrados: " <<listadoInformacion.size() <<endl;
    cout<<endl<<endl<<endl;
    //LLenado de Heap O(nlogn) y vaciado para guardar TopAcces.txt (nlogn) 
    listadoInformacion.topAccess();
    //Impresion de las 5 Ip que tuvieron mayor cantidad de intentos negados
    FiveTopAccess();
    return 0;
}