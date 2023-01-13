#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <math.h>
#include <fstream>

using namespace std;

class HashTable_Chain{
    int capacity;
    list<int> *table;
    private:
        int getPrime(int); //Complejidad O(n)
        bool checkPrime(int); //Complejidad O(sqrt(n))
        int hashFunction(int); //ComplejidadO(1)
    public:
        HashTable_Chain(){ //Complejidad O(1)
            this->capacity = 0;
            table = new list<int>[capacity];
        };
        HashTable_Chain(int n){ //Complejidad O(nsqrt(n))
            int size = getPrime(n);
            this->capacity = size;
            table = new list<int>[capacity];
        };
        ~HashTable_Chain(){
            delete[] table;
            cout << "\nHashTable_Chain deleted. " << endl;
        };
        void insertItem(int); //O(1)
        void deleteItem(int); //O(1)
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
int HashTable_Chain::hashFunction(int key)
{
    return key % this->capacity;
}
/*Insercion de dato en indice correspondiente y en caso de colision encadenamiento*/
void HashTable_Chain::insertItem(int data)
{
    int index = hashFunction(data);
    table[index].push_back(data);
}
/*Eliminacion de elemento en la estructura*/
void HashTable_Chain::deleteItem(int key)
{
    int index = hashFunction(key);
    table[index].remove(key);
}
/*Impresion de la estructura*/
void HashTable_Chain::displayHash()
{
    for (int i = 0; i < this->capacity; i++)
    {
        cout << "table[" << i << "]";

        for (auto x : table[i])
            cout << " --> " << x;

        cout << endl;
    }
}
/*Llenado de estructura apartir de archivo de texto*/
void HashTable_Chain::fillHash(string fileName){
    ifstream file;
    file.open(fileName);
    int data;
    stack<int> stack;
    while (file >> data)
    {
        stack.push(data);
    }
    int size = getPrime(stack.size());
    this->capacity = size;
    table = new list<int>[capacity];
    while (stack.size()>0)
    {
        insertItem(stack.top());
        stack.pop();
    }
}

/*........................................*/

class HashTable_Quadratic{
    int capacity;
    int *table;
    private:
        int getPrime(int); //Complejidad O(n)
        bool checkPrime(int); //Complejidad O(sqrt(n))
        int hashFunction(int); //ComplejidadO(1)
        int quadratic(int,int);
    public:
        HashTable_Quadratic(){ //Complejidad O(1)
            this->capacity = 0;
            table = new int[capacity];
        };
        HashTable_Quadratic(int n){ //Complejidad O(nsqrt(n))
            int size = getPrime(n);
            this->capacity = size;
            table = new int[capacity];
        };
        ~HashTable_Quadratic()
        {
            delete[] table;
            cout << "\nHashTable_Quadratic deleted. " << endl;
        };
        void insertItem(int); //O(n)
        void deleteItem(int); //O(n)
        void displayHash(); //O(n+m)
        void fillHash(string); //O(n)
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
int HashTable_Quadratic::hashFunction(int key)
{
    return key % this->capacity;
}
/*Insercion de dato en indice correspondiente y en caso de colision busqueda de indice vacio*/
void HashTable_Quadratic::insertItem(int data)
{
    int index = hashFunction(data);
    if (table[index] < 0)
        table[index] = data;
    else{
        int i = 0;
        while(table[index] > 0 && i < this->capacity){
            index = quadratic(index, i);
            if (table[index] < 0)
            {
                table[index] = data;
                break;
            }
            else
                i++;
        }
    }
}
/*Eliminacion de elemento en la estructura*/
void HashTable_Quadratic::deleteItem(int key)
{
    int index = hashFunction(key);
    table[index] = -1;
}
/*Impresion de la estructura*/
void HashTable_Quadratic::displayHash()
{
    for (int i = 0; i < this->capacity; i++)
    {
        cout << "table[" << i << "]";
        if (table[i] > 0)
            cout << " --> " << table[i];
        cout << endl;
    }
}
/*Funcion para calculo de posicion vacia*/
int HashTable_Quadratic::quadratic(int index, int i){
    return (index + 2*i + 3*i^2) % this->capacity;
}
/*Llenado de estructura apartir de archivo de texto*/
void HashTable_Quadratic::fillHash(string fileName){
    ifstream file;
    file.open(fileName);
    int data;
    stack<int> stack;
    while (file >> data)
    {
        stack.push(data);
    }
    int size = getPrime(stack.size());
    this->capacity = size;
    table = new int[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = -1;
    
    while (stack.size()>0)
    {
        insertItem(stack.top());
        stack.pop();
    }
}

/*........................................*/

int main(){

    const int ArchivosPrueba = 4;
    string arrPruebas[ArchivosPrueba];
    for (int i = 0; i < sizeof(arrPruebas)/ sizeof(arrPruebas[0]); i++)
    {   
        string prueba = "Prueba" + to_string(i+1) + ".txt";
        arrPruebas[i] = prueba;
    }
    
    for (int i = 0; i < sizeof(arrPruebas)/ sizeof(arrPruebas[0]); i++)
    {
        if (i>0)
        cout<<"\n...........................\n";
        
        cout << "\n\nTEST: " << arrPruebas[i] << endl;
        HashTable_Chain hash_chain;
        HashTable_Quadratic hash_quadratic;
        hash_chain.fillHash(arrPruebas[i]);
        hash_quadratic.fillHash(arrPruebas[i]);

        cout<<"\nChaining implementation\n";
        hash_chain.displayHash();
        cout<<"\nQuadratic probing implementation\n";
        hash_quadratic.displayHash();
        cout<<"\n...........................\n";
    }
    
    return 0;
}