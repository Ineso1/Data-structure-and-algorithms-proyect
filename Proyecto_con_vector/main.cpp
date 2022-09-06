#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int dateIntCode(vector<string> &vec){
    try
    {
        string month = vec[0];
        string day = vec[1];
        string hour = vec[2];

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
        return 0;
    }
}

void lecturaArchivo(vector<vector<string>> &matriz, string direccionArchivo){
    ifstream archivo;
    archivo.open(direccionArchivo);
    string mes,dia, hora, direccionIP, razon;
    vector<string> renglon;
    while (archivo >> mes>> dia>> hora>> direccionIP)
    {
        getline(archivo, razon);
        renglon = {mes, dia, hora, direccionIP, razon};
        matriz.push_back(renglon);
    }
    cout<<"...Lectura Completa...";
}

void swap(vector<string> &a, vector<string>&b){
    vector<string> aux = a;
    a = b;
    b = aux;
}

void bubbleSort(vector<vector<string>> &matriz){
    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = i; j < matriz.size(); j++)
        {
            if (dateIntCode(matriz[i]) > dateIntCode(matriz[j]))
            {
                swap(matriz[j], matriz[i]);
            }
        }   
    } 
}

void printSortedList(vector<vector<string>> &matriz){
    ofstream file;
    file.open("sorted.txt");
    for(int i =0; i<matriz.size();i++){
        for (int j = 0; j < matriz[i].size(); j++)
        {
            file << matriz[i][j]<<" ";
        }
        file << "\n";
    }
}

int main(){
    vector<vector<string>> matriz;
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
        lecturaArchivo(matriz, "bitacora.txt");
        printSortedList(matriz);
        cout << "El resultado fue guardado en un archivo llamado sorted.txt";

    }
    else if (op == 2)
    {
        lecturaArchivo(matriz, "sorted.txt");
        findRange(matriz);
        cout << "El resultado fue guardado en un archivo llamado resultadoBusqueda.txt";
    }
    else{
        cout << "Opcion no valida";
    }
    return 0;
}

int main(){
    vector<vector<string>> matriz;
    lecturaArchivo(matriz, "bitacora.txt");
    bubbleSort(matriz);
    cout<<"sorted";
    printSortedList(matriz);
    return 0;
}