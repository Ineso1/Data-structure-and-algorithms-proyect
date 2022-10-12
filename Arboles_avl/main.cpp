#include "AvlTree.h"
#include <iostream>
#include <fstream>
using namespace std;

void lectura(AvlTree& tree){
    ifstream archivo;
    archivo.open("lista.txt");
    int dato;
    while (archivo >> dato)
    {
        tree.insert(dato);
    }
}

int main(){
    AvlTree tree;
    lectura(tree);
    tree.InOrder();
    return 0;
}