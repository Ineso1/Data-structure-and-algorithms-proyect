#include <iostream>
#include <list>
#include <math.h>

using namespace std;

class HashTable
{
private:
    int capacity;
    list<int> *table;

public:
    HashTable(int V)
    {
        int size = getPrime(V);
        this->capacity = size;
        table = new list<int>[capacity];
    }

    ~HashTable()
    {
        delete[] table;
        cout << "\nDestructor: HashTble deleted. " << endl;
    }

    bool checkPrime(int);
    int getPrime(int);

    void insertItem(int);
    void deleteItem(int);
    int hashFunction(int);
    void displayHash();
};

bool HashTable::checkPrime(int n)
{
    if (n == 1 || n == 0)
        return false;

    int sqr_root = sqrt(n);
    for (int i = 2; i <= sqr_root; i++)
        if (n % i == 0)
            return false;
    return true;
}

int HashTable::getPrime(int n)
{
    if (n % 2 == 0)
        n++;
    while (!checkPrime(n))
        n += 2;
    return n;
}

int HashTable::hashFunction(int key)
{
    return key % this->capacity;
}

void HashTable::insertItem(int data)
{
    int index = hashFunction(data);
    table[index].push_back(data);
}

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    table[index].remove(key);

    // Alternative:
    // int index = hashFunction(key);
    // list<int>::iterator i;

    // for (i = table[index].begin(); i != table[index].end(); i++)
    // {
    //     if (*i == key)
    //         break;
    // }

    // if (i != table[index].end())
    //     table[index].erase(i);
}

void HashTable::displayHash()
{
    for (int i = 0; i < this->capacity; i++)
    {
        cout << "table[" << i << "]";

        for (auto x : table[i])
            cout << " --> " << x;

        cout << endl;
    }
}

int main()
{
    int data[] = {231, 321, 212, 321, 433, 262};
    int n = sizeof(data) / sizeof(data[0]);

    HashTable h(7);

    for (int i = 0; i < n; i++)
        h.insertItem(data[i]);

    h.displayHash();

    cout << "\nDeleting element:" << endl;
    h.deleteItem(231);
    h.displayHash();

    return 0;
}