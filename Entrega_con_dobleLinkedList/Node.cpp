#include "Node.h"
#include <map>
#include <string>

//Constructor Nodo
Node::Node(){
    month = "";
    day = "";
    hour = "";
    ip = "";
    reason = "";
    nextNode = nullptr;
    previousNode = nullptr;
}

//Sobrecarga nodo
Node::Node(std::string &month, std::string &day, std::string &hour, std::string &ip, std::string &reason, Node* prev, Node* next) {
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->ip = ip;
    this->reason = reason;
    this->nextNode = next;
    this->previousNode = prev;
}

//Destructor Nodo
Node::~Node(){
    delete &month;
    delete &day;
    delete &hour;
    delete &ip;
    delete &reason;
    delete nextNode;
    delete previousNode;
}

//Getter de datos de la lista
std::string Node::getData(){
    std::string res = this->month + " " + this->day + " " + this->hour + " " + this->ip + " " + this->reason;
    return res;
}

//Seter de datos de la lista
void Node::setData(std::string &month, std::string &day, std::string &hour, std::string &ip, std::string &reason){
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->ip = ip;
    this->reason = reason;
}

//Sobrecarga para ostream de nodo
std::ostream& operator <<(std::ostream& os, const Node& node){
    os << node.month + " " + node.day + " " + node.hour + " " + node.ip + " " + node.reason;
    return os;
}

int Node::dateIntCode(){
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

        return std::stoi(result);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}

int Node::ipIntCode(){
    try
    {
        std::string result;
        result = ip[0]+ip[1]+ip[2]
        +ip[4]+ip[5]+ip[6]
        +ip[8]+ip[9]+ip[10];
        return std::stoi(result);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}