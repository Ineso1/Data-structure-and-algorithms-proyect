#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
    public:
    std::string month, day, hour, ip, reason;
    Node *nextNode;
    Node *previousNode;
    Node(); //Constructor sin parametros
    Node(std::string&, std::string&, std::string&, std::string&, std::string&, Node*, Node*);  //Constructor con datos del registro
    std::string getData();  //Obtencion de los datos del nodo en formato
    void setData(std::string&, std::string&, std::string&, std::string&, std::string&); //Sobrescritura de los datos del nodo
    ~Node(); //Destructor de Nodo
    friend std::ostream &operator <<(std::ostream& salida, const Node&); //Sobrecarga de operador para imprimir dato del nodo
    int dateIntCode(); //Codificacion de fecha para comparacion
    unsigned long long ipIntCode(); //Codificacion de ip para comparacion
};

#endif // NODE_H
