#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

class Node{
    public:
    string month, day, hour, ip, reason;
    Node *left;
    Node *right;
    Node(){     //Constructor vacio
        month = "";
        day = "";
        hour = "";
        ip = "";
        reason = "";
        left = NULL;
        right = NULL;
    }
    Node(string &month, string &day, string &hour, string &ip, string &reason){      //Constructor de todos los parametros
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->reason = reason;
        this->left = NULL;
        this->right = NULL;
    }
    Node(string &month, string &day, string &hour, string &ip, string &reason, Node* left, Node* right){      //Constructor de todos los parametros
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->reason = reason;
        this->left = left;
        this->right = right;
    }
    string getData(){       //Return de fecha en formato "mes dia hora:minuto:segundo.milisegundos ip(XXX.XXX.XXX:XXXX) razon"
        string res = this->month + " " + this->day + " " + this->hour + " " + this->ip + " " + this->reason;
        return res;
    }
    void setData(string &month, string &day, string &hour, string &ip, string &reason){     //Reescritura de fecha
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->reason = reason;
    }
    ~Node(){
        delete left;
        delete right;
    }
    int dateIntCode(){
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
    unsigned long long ipIntCode(){
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

class BST{
    Node* head;
    int orderType = 0;
    private:
        void insertNode(Node*&, Node*&, int&); //Funciona
        int sortType(Node*&, Node*&, int&); //Dependiendo el tipo de ordenamiento se requiera (1 por Ip, 2 por Fecha)
        void deleteNode(Node*&, string&, string&, string&, string&, string&);
        void PreOrder(Node*&); //Funciona
        void InOrder(Node*&); //Funciona
        void PostOrder(Node*&); //Funciona
        void SubstituteToMin(Node*&, Node*&);
        void searchNode(Node*&, string&, string&);
        //void deleteTree(Node*&);

    public:
        BST(){ Node* head = NULL; };  
        //~BST(){ deleteTree(head); };
        void fillBST(std::string, int); 
        void insert(string&, string&, string&, string&, string&);
        void InOrder(){ InOrder(head); }; //Lista
        void PreOrder(){ PreOrder(head); };
        void PostOrder(){ PostOrder(head); };
        void deleteNode(string&, string&, string&, string&, string&);
        void searchRange(string&, string&);
};

int BST::sortType(Node*&node, Node*&newNode, int& code){
    if (code == 1)
    {   
        unsigned long long nodeCode = node->ipIntCode(); 
        unsigned long long newNodeCode = newNode->ipIntCode();
        if (nodeCode > newNodeCode)
            return 1;
        else if (nodeCode < newNodeCode)
            return -1;
        return 0;
    }
    else if (code == 2){
        int nodeCode = node->dateIntCode();
        int newNodeCode = newNode->dateIntCode();
        if (nodeCode > newNodeCode)
            return 1;
        else if (nodeCode < newNodeCode)
            return -1;
        return 0;
    }
    throw invalid_argument("Opcion de ordenamiento inexistente");
}

void BST::insertNode(Node* &node, Node* &newNode, int &condition){
    if (node == NULL)
    {
        node = newNode;
    }
    else{
        int step = sortType(node, newNode, condition);
        if(step == 1){
            insertNode(node->left, newNode, condition);
        }
        else if(step == -1){
            insertNode(node->right, newNode, condition);
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
    file.open(fileName);
    string month, day, hour, ip, reason;
    try{
    while (file >> month>> day>> hour>> ip)
        {
            getline(file, reason);
            Node* newNode = new Node(month, day, hour, ip, reason);
            insertNode(head, newNode, condition);
        }
    }
    catch(invalid_argument e){
        cerr << e.what() << endl;
    }
}

void BST::searchRange(string& condition1, string& condition2){
    searchRange(head, condition1, condition2);
}

// void BST::searchRange(Node*& node, string& condition1, string& condition2){
//     if (node != NULL){
//         Node* newNode = new Node();
//         newNode->setData("", "", "", "", "");
//     }
// }

int main(){
    BST listadoInformacion;
    listadoInformacion.fillBST("bitacoraPrueba.txt", 1);
    listadoInformacion.InOrder();
    return 0;
}