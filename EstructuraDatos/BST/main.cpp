#include <iostream>
#include "BST.h"
using namespace std;

int main(){
    BST arbol;
    arbol.llenarBST("lista.txt");
    arbol.InOrder();
    cout << endl;
    arbol.PreOrder();
    cout << endl;
    arbol.PostOrder();
    cout << endl;
    int x = 23;
    arbol.deleteNode(x);
    arbol.PostOrder();
    cout << endl;
    arbol.BFT();
    return 0;
}