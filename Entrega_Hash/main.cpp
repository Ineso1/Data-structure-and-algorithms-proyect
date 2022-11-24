#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <math.h>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class Node{
    public:
    string month, day, hour, ip;
    list<string> Access;
    list<int> Port;

    Node(){     //Constructor vacio
        month = "";
        day = "";
        hour = "";
        ip = "";
    }
    Node(string &month, string &day, string &hour, string &ip, string &reason){      //Constructor de todos los parametros
        this->Access.push_back(reason);
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
    }
    void addAttempt(string access, int port){ 
        Access.push_back(access);
        Port.push_back(port); 
    }
    string getData(){       //Return de fecha en formato "mes dia hora:minuto:segundo.milisegundos ip(XXX.XXX.XXX:XXXX) razon"
        string ipNoPort = ip;
        ipNoPort.erase(ipNoPort.length()-5);
        string res = this->month + " " + this->day + " " + this->hour + " " + ipNoPort + "\n";
        return res;
    }
    void getAttempts(){ 
        for (auto x : Access)
        {
            cout << x << " :\t";
        }
        for (auto y : Access)
        {
            cout << y << " :\t";
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
    int ipPort(string ip){
        int dig = 0;
        string cuarteto = "";
        for(int i = 0; ip.length(); i++){
            if(ip[i] == ':')
                {
                    cuarteto += ip[i];
                    dig++;
                }
        }
        return stoi(cuarteto);
    }
};

class HashTable_Chain{
    int capacity;
    list<Node*> *table;
    private:
        int getPrime(int); //Complejidad O(n)
        bool checkPrime(int); //Complejidad O(sqrt(n))
        unsigned long long hashFunction(unsigned long long); //ComplejidadO(1)
    public:
        HashTable_Chain(){ //Complejidad O(1)
            this->capacity = 0;
            table = new list<Node*>[capacity];
        };
        HashTable_Chain(int n){ //Complejidad O(nsqrt(n))
            int size = getPrime(n);
            this->capacity = size;
            table = new list<Node*>[capacity];
        };
        ~HashTable_Chain(){
            delete[] table;
            cout << "\nHashTable_Chain deleted. " << endl;
        };
        void insertItem(Node*); //O(1)
        void deleteItem(string); //O(1)
        void displayHash();   //O(n+m)
        void fillHash(string); //O(n)
};

/*Verificacion si es numero primo*/
bool HashTable_Chain::checkPrime(int n){
    if (n == 0 || n == 1)
        return false;
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i++)
        if (n % i == 0)
            return false;
    return true;      
}
/*Obtenicion de numero primo mas cercno*/
int HashTable_Chain::getPrime(int n)
{
    if (n % 2 == 0)
        n++;
    while (!checkPrime(n))
        n += 2;
    return n;
}
/*Procesamiento de llave a numero de indice valido en la estructura*/
unsigned long long HashTable_Chain::hashFunction(unsigned long long key)
{
    return key % this->capacity;
}
/*Insercion de dato en indice correspondiente y en caso de colision encadenamiento*/
void HashTable_Chain::insertItem(Node* data)
{
    unsigned long long index = hashFunction(data->ipIntCode());
    table[index].push_back(data);
}
/*Eliminacion de elemento en la estructura*/
void HashTable_Chain::deleteItem(string ip)
{
    unsigned long long index = hashFunction(stoi(ip));
    //table[index].remove(ip);
}
/*Impresion de la estructura*/
void HashTable_Chain::displayHash()
{
    for (int i = 0; i < this->capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x->getData() << "\t";
        cout << endl;
    }
}
/*Llenado de estructura apartir de archivo de texto*/
void HashTable_Chain::fillHash(string fileName){
    ifstream file;
    file.open(fileName);
    string month, day, hour, ip, reason;
    stack<Node*> stack;
    while (file >> month>> day>> hour>> ip)
    {
        getline(file, reason);
        Node* newNode = new Node(month, day, hour, ip, reason);
        stack.push(newNode);
    }
    int size = getPrime(stack.size());
    this->capacity = size;
    table = new list<Node*>[capacity];
    while (stack.size()>0)
    {
        insertItem(stack.top());
        stack.pop();
    }
}

int main(){
    HashTable_Chain hash_chain;
    hash_chain.fillHash("bitacoraPrueba.txt");
    hash_chain.displayHash();
    
    return 0 ;
}