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
    try
    {
        
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
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    
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
    cout << "Comienzo de ordenamiento\nEsto podria tomar mas de 10 min no se espante\n";
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
        cout<<"....Ordenamiento de Datos Exitoso....";
    }
}

void lecturaArchivo(Node* &head, string direccionArchivo){
    cout<<"....Comienzo de carga....";
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
            tmp->next = newNode;
            tmp = tmp->next;
        }
        cout<<"....Carga de datos en la matriz exitosa....";
    }
}

void printSortedList(Node* &head){
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

void findRange(Node* &head){
    Node *tmp = head;
    string monthFirst,dayFirst,hourFirst,minuteFirst,secondFirst;
    string monthLast,dayLast,hourLast,minuteLast,secondLast;
    cout<<"\nBusqueda por rango de fecha\nIntroduce la fecha deceada con espacios entre caracteristicas con el siguiente formato\n(month/ day/ hour/ minute/ second)\n Ejemplo segundo limite (Jun 1 10 30 00)\n Ejemplo primer limite (Oct 10 01 25 00)\nIntroduce el primer limite:\n";
    cin >> monthFirst >> dayFirst >> hourFirst >> minuteFirst >> secondFirst;
    cout<<"\nIntroduce el segundo limite de fecha\n";
    cin >> monthLast >> dayLast >> hourLast >> minuteLast >> secondLast;
    string hourFormatFirst = hourFirst + ":" + minuteFirst + ":" + secondFirst;  
    string hourFormatLast = hourLast + ":" + minuteLast + ":" + secondLast;  
    ofstream file;
    file.open("resultadoBusqueda.txt");
    while (tmp !=NULL)
    {   
        if(dateIntCode(monthFirst,dayFirst,hourFormatFirst) > dateIntCode(monthLast,dayLast,hourFormatLast)){
            string aux;
            aux = monthFirst;
            monthFirst = monthLast;
            monthLast = aux;
            aux = dayFirst;
            dayFirst = dayLast;
            dayLast = aux;
            aux = hourFormatFirst;
            hourFirst = hourLast;
            hourLast = aux;
        }
        if (dateIntCode(monthFirst,dayFirst,hourFormatFirst) < dateIntCode(tmp->month,tmp->day,tmp->hour) && dateIntCode(tmp->month,tmp->day,tmp->hour) < dateIntCode(monthLast,dayLast,hourFormatLast))
        {
            file << tmp->month << " " 
            << tmp->day << " " 
            << tmp->hour << " " 
            << tmp->ip 
            << tmp->reason <<"\n";
            tmp = tmp->next;
        }
        tmp = tmp->next;
    }
    file.close();
}

int main(){
    Node *head;
    int op;
    cout << "\n\t\tLista de peticiones\n"
    <<"\t1.Lectura y ordenamiento de listado de peticiones"
    <<"\n\t2.Busqueda en datos preordenados"
    <<"\n\nOpcion: ";
    try
    {
        cin >> op;

    }
    catch(const std::exception& e)
    {
        cout << "Opcion no valida\n";
    }
    if (op == 1)
    {
        lecturaArchivoSort(head, "bitacora.txt");
        printSortedList(head);
        cout << "El resultado fue guardado en un archivo llamado sorted.txt";

    }
    else if (op == 2)
    {
        lecturaArchivo(head, "sorted.txt");
        findRange(head);
        cout << "El resultado fue guardado en un archivo llamado resultadoBusqueda.txt";
    }
    else{
        cout << "Opcion no valida";
    }
    return 0;
}
