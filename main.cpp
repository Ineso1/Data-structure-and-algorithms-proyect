#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct Node
{
  string month,day,hour,ip,reason;
  struct Node *next;
};

int dateIntCode(string month,string day, string hour){
    map<string, string> monthNum = {
        {"Jun", "6"},
        {"Jul", "7"},
        {"Aug", "8"},
        {"Sep", "9"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dic", "12"}
    };
    string result;
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

int sortNode(Node* &head, Node* &actual){
    Node *tmp = head;
    while(tmp->next !=NULL){
        int tmpDate = dateIntCode(tmp->month, tmp->day, tmp->hour), 
        actualDate = dateIntCode(actual->month, actual->day, actual->hour),
        tmpNextDate = dateIntCode(tmp->next->month, tmp->next->day, tmp->next->hour );
        if(tmpDate >= actualDate && actualDate > tmpNextDate){
            actual->next = tmp->next;
            tmp->next = actual;
            return 0;
        }
        else if(tmpDate < actualDate){
            actual->next = head; 
            head = actual;
            return 0;
        }
        tmp = tmp->next;
    }
    tmp->next = actual;
    tmp = tmp->next;
    return -1;
    
}

void lecturaArchivo(Node* &head){
    string direccionArchivo = "bitacora.txt";
    ifstream archivo;
    archivo.open(direccionArchivo);
    if (archivo.is_open()){
        string mes,dia, hora, direccionIP, razon;
        Node *tmp;
        if (archivo >> mes>> dia>> hora>> direccionIP)
        {
            getline(archivo, razon);
            Node *newNode = new Node();
            newNode->month = mes;
            newNode->day = dia;
            newNode->hour = hora;
            newNode->ip = direccionIP;
            newNode->reason = razon;
            newNode->next = NULL;
            head = newNode;
            tmp = head;
        }

        while (archivo >> mes>> dia>> hora>> direccionIP)
        {
            getline(archivo, razon);
            Node *newNode = new Node();
            newNode->month = mes;
            newNode->day = dia;
            newNode->hour = hora;
            newNode->ip = direccionIP;
            newNode->reason = razon;
            newNode->next = NULL;
            sortNode(head,newNode);
        }
        cout<<".";
    }
}

void printSortedList(Node *head){
    ofstream file;
    file.open("sorted.txt");
    Node *tmp = head;
    while(tmp !=NULL){
        file << tmp->month << " " 
        << tmp->day << " " 
        << tmp->hour << " " 
        << tmp->ip 
        << tmp->reason <<"\n";
        tmp = tmp->next;
    }
}

int main(){
    Node *head;
    lecturaArchivo(head);
    // Node *tmp = head;
    // while(tmp !=NULL){
    //     cout << tmp->month << " - > ";
    //     tmp = tmp->next;
    // }
    // cout << endl;
    // tmp = head;
    // while(tmp !=NULL){
    //     cout << dateIntCode(tmp->month, tmp->day, tmp->hour) << " - > ";
    //     tmp = tmp->next;
    // }
    printSortedList(head);
    return 0;
}