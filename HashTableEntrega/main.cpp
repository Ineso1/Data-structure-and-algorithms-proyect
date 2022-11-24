#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <math.h>
#include <fstream>

using namespace std;

class Node{
    public:
    string month, day, hour, ip;
    list<string> Date;
    list<string> Access;
    list<int> Port;

    Node(){     //Constructor vacio
        month = "";
        day = "";
        hour = "";
        ip = "";
    }
    Node(string &month, string &day, string &hour, string &ip, string &reason){      //Constructor de todos los parametros
        this->month = month;
        this->day = day;
        this->hour = hour;
        string ipNoPort = ip;
        ipNoPort.erase(ipNoPort.length()-5);
        this->ip = ipNoPort;
        string date =  month + " " + day + " " + hour;
        addAttempt(reason, ipPort(ip), date);
    }
    void addAttempt(string access, int port, string date){ 
        Access.push_back(access);
        Port.push_back(port);
        Date.push_back(date); 
    }
    string getData(){       //Return de fecha en formato "mes dia hora:minuto:segundo.milisegundos ip(XXX.XXX.XXX:XXXX) razon"
        string ipNoPort = ip;
        string res = "IP: " + ipNoPort + "\n";
        return res;
    }
    void getAttempts(){ 
        cout << "\tDate:\n";
        for (auto z : Date)
        {
            cout << "\t\t" << z << "\n";
        }
        cout << "\tReason:\n";
        for (auto x : Access)
        {
            cout << "\t\t" << x << "\n";
        }
        cout << "\tPort:\n";
        for (auto y : Port)
        {
            cout << "\t\t" << y << "\n";
        }
        cout<<"\n\n";
    }
    void saveAttempts(ofstream &file){
        file << "\tDate:\n";
        for (auto z : Date)
        {
            file << "\t\t" << z << "\n";
        }
        file << "\tReason:\n";
        for (auto x : Access)
        {
            file << "\t\t" << x << "\n";
        }
        file << "\tPort:\n";
        for (auto y : Port)
        {
            file << "\t\t" << y << "\n";
        }
        file<<"\n\n";
    };
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
        for(int i = 0; i < ip.length(); i++){
            cuarteto += ip[i];
            dig++;
            if(ip[i] == ':')
                {
                    cuarteto = "";
                    dig = 0;
                }
        }
        return stoi(cuarteto);
    }
};


class HashTable_Quadratic{
    int capacity;
    Node** table;
    private:
        int getPrime(int); //Complejidad O(n)
        bool checkPrime(int); //Complejidad O(sqrt(n))
        unsigned long long hashFunction(unsigned long long); //ComplejidadO(1)
        unsigned long long quadratic(unsigned long long, unsigned long long);
    public:
        HashTable_Quadratic(){ //Complejidad O(1)
            this->capacity = 0;
            table = new Node*[capacity];
        };
        HashTable_Quadratic(int n){ //Complejidad O(nsqrt(n))
            int size = getPrime(n);
            this->capacity = size;
            table = new Node*[capacity];
        };
        ~HashTable_Quadratic()
        {
            delete[] table;
            cout << "\nHashTable_Quadratic deleted. " << endl;
        };
        unsigned long long ipIntCode(string);
        void insertItem(Node*); //O(n)
        void deleteItem(string); //O(n)
        void saveHash(); //O(n+m)
        void fillHash(string); //O(n)
        void getIpData(string ip);
};

/*Verificacion si es numero primo*/
bool HashTable_Quadratic::checkPrime(int n){
    if (n == 0 || n == 1)
        return false;
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i++)
        if (n % i == 0)
            return false;
    return true;      
}
/*Obtenicion de numero primo mas cercno*/
int HashTable_Quadratic::getPrime(int n)
{
    if (n % 2 == 0)
        n++;
    while (!checkPrime(n))
        n += 2;
    return n;
}
/*Procesamiento de llave a numero de indice valido en la estructura*/
unsigned long long HashTable_Quadratic::hashFunction(unsigned long long key)
{
    return key % this->capacity;
}
/*Insercion de dato en indice correspondiente y en caso de colision busqueda de indice vacio*/
void HashTable_Quadratic::insertItem(Node* data)
{
    unsigned long long index = hashFunction(data->ipIntCode());
    if (table[index] == NULL)
        table[index] = data;
    else{
        unsigned long long i = 0;
        while(table[index] != NULL && i < this->capacity){
            if (table[index]->ipIntCode() == data->ipIntCode())
            {
                table[index]->addAttempt(data->Access.front(), data->Port.front(), data->Date.front());
                break;
            }
            index = quadratic(index, i);
            if (table[index] == NULL)
            {
                table[index] = data;
                break;
            }
            else{
                i++;
            }
        }
    }
}
/*Eliminacion de elemento en la estructura*/
unsigned long long HashTable_Quadratic::ipIntCode(string ip){  //Codificacion ip
    try
    {
        string result = "";
        int dig = 0;
        int sep = 0;
        string cuarteto = "";
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

void HashTable_Quadratic::deleteItem(string key)
{
    unsigned long long index = hashFunction(ipIntCode(key));
    table[index] = NULL;
}
/*Impresion de la estructura*/
void HashTable_Quadratic::saveHash()
{
    ofstream file;
    file.open("Hash.txt");
    for (int i = 0; i < this->capacity; i++)
    {
        if (table[i] != NULL){ 
            file << "table[" << i << "]";
            file << " --> " << table[i]->getData();
            table[i]->saveAttempts(file);
        }
    }
}
/*Funcion para calculo de posicion vacia*/
unsigned long long HashTable_Quadratic::quadratic(unsigned long long index, unsigned long long i){
    return (index + 1*i + 1*i^2) % this->capacity;
}
/*Llenado de estructura apartir de archivo de texto*/
void HashTable_Quadratic::fillHash(string fileName){
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
    table = new Node*[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = NULL;
    while (stack.size()>0)
    {
        insertItem(stack.top());
        stack.pop();
    }
}

void HashTable_Quadratic::getIpData(string ip){
    unsigned long long index = hashFunction(ipIntCode(ip));
    if (table[index] == NULL )
    {
        cout<<"\nNot found\t"<<ip<<endl;
        return;
    }
    if (table[index]->ipIntCode() == ipIntCode(ip)){
        ofstream file;
        file.open("Consulta.txt");
        cout<<table[index]->getData();
        file<<table[index]->getData();
        table[index]->getAttempts();
        table[index]->saveAttempts(file);
    }
    else{
        unsigned long long i = 0;
        while(table[index]->ipIntCode() != ipIntCode(ip) && i < this->capacity){
            index = quadratic(index, i);
            i++;
        }
        if (table[index]->ipIntCode() == ipIntCode(ip))
            {
                ofstream file;
                file.open("Consulta.txt");
                cout<<table[index]->getData();
                table[index]->getAttempts();
                file<<table[index]->getData();
                table[index]->saveAttempts(file);
                return;
            }
        cout<<"\nNot found\t"<<ip<<endl;
    }
}

/*........................................*/

int main(){

    HashTable_Quadratic hash_quadratic;
    hash_quadratic.fillHash("bitacora.txt");
    hash_quadratic.saveHash();
    cout<<"\nSe ha generado archivo Hash.txt\n";
    bool programCounter = true;
    string ip, op;
    while (programCounter)
    {
        cout<<"Ingresa la Ip por consultar\nEjemplo:\t423.2.230.77\n---> ";
        cin>>ip;
        cout<<endl;
        cout<<"...............................................\n";
        hash_quadratic.getIpData(ip);
        cout<<"...............................................\n";
        cout<<"\nArchivo Consulta.txt generado con la consulta\n";
        cout<<"Continuar? [y/n] ";
        cin>>op;
        if(op !="y"){
            programCounter = false;
        }
    }
    return 0;
}