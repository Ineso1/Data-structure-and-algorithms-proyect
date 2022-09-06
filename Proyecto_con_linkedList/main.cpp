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

void lecturaArchivoSort(Node* &head, string direccionArchivo){
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

void lecturaArchivo(Node* &head, string direccionArchivo){
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
    file.close();
}

void findRange(Node *head){
    Node *tmp = head;
    string monthFirst,dayFirst,hourFirst,minuteFirst,secondFirst;
    string monthLast,dayLast,hourLast,minuteLast,secondLast;
    cout<<"Busqueda por rango de fecha\nIntroduce la fecha deceada con espacios entre caracteristicas con el siguiente formato\nmonth day hour minute second -> (00 00 00 00 00)";
    cin >> monthFirst >> dayFirst >> hourFirst >> minuteFirst >> secondFirst;
    cout<<"Busqueda por rango de fecha\nIntroduce la fecha deceada con espacios entre caracteristicas con el siguiente formato\nmonth day hour minute second -> (00 00 00 00 00)";
    cin >> monthLast >> dayLast >> hourLast >> minuteLast >> secondLast;
    string hourFormatFirst = hourFirst + ":" + minuteFirst + ":" + secondFirst;  
    string hourFormatLast = hourLast + ":" + minuteLast + ":" + secondLast;  
    while (tmp !=NULL)
    {
        if (dateIntCode(monthFirst,dayFirst,hourFormatFirst) )
        {
            /* code */
        }
        
        tmp = tmp->next;
    }
    
}

int main(){
    Node *head;
    // lecturaArchivoSort(head, "bitacora.txt");
    lecturaArchivo(head, "sorted.txt");
    printSortedList(head);
    return 0;
}