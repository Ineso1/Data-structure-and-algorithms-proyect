/*
Inés Alejandro Garcia Mosqueda A00834571
Jesus Fong Ruiz A01254062
https://github.com/Ineso1/Data-structure-and-algorithms-proyect/tree/main/Entrega_con_grafos
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>


using namespace std;

class Node{     //Clase para facilitar la insercion de subip dentro del grafo
    public:
    int n, s;
    Node(int n, int s){
        this->n = n;
        this->s = s;
    };
};

class DegreeNode{   //Clase que facilita el uso de Heap para ordenamiento por outdegree e indegree
    public:
        int value;
        int outDegree;
        int inDegree;
        DegreeNode(){
            value = -1;
            outDegree = -1;
            inDegree = -1;
        }
        DegreeNode(int value, int outDegree, int inDegree){
            this->value = value;
            this->outDegree = outDegree;
            this-> inDegree = inDegree;
        }
};

class RNode{    //Clase que contiene la informacion y funciones para el manejo de los registros
    public:
    string month, day, hour, ip, reason;
    RNode(){     //Constructor vacio
        month = "";
        day = "";
        hour = "";
        ip = "";
        reason = "";
    }
    RNode(string &month, string &day, string &hour, string &ip, string &reason){      //Constructor de todos los parametros
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->reason = reason;

    }
    RNode(string &month, string &day, string &hour, string &ip, string &reason, RNode* left, RNode* right){      //Constructor de todos los parametros
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->reason = reason;
    }
    string getData(){       //Return de fecha en formato "mes dia hora:minuto:segundo.milisegundos ip(XXX.XXX.XXX:XXXX) razon"
        string ipNoPort = ip;
        ipNoPort.erase(ipNoPort.length()-5);
        string res = this->month + " " + this->day + " " + this->hour + " " + ipNoPort + " " + this->reason;
        return res;
    }
    void setData(string &month, string &day, string &hour, string &ip, string &reason){     //Reescritura de fecha
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->reason = reason;
    }
    int dateIntCode(){  //Codificacion de fecha
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

            return stoi(result);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }
    unsigned long long ipIntCode(){  //Codificacion ip
        try
        {
            std::string result = "";
            int dig = 0;
            int sep = 0;
            std::string cuarteto = "";
            for (int i = 0; i < ip.length(); i++)
            {   
                if(ip[i] != '.' && ip[i] != ':')
                {
                    cuarteto += ip[i];
                    dig++;
                }
                else{
                    if (ip[i] == ':')
                    break;
                    while (dig<3)
                    {
                        cuarteto = "0" + cuarteto;
                        dig++;
                    }
                    dig = 0;
                    result += cuarteto;
                    cuarteto = "";
                }
            }
            result+=cuarteto;
            return std::stoull(result);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << ": Algun error por aqui" << '\n';
            return -1;
        }
    }
    void IpSection(int res[]){  //Calback de seccionamiento de ip por componente
        string cuarteto = "";
        int numCuarteto = 0; 
        for (int i = 0; i < ip.length(); i++)
            {
                if(ip[i] != '.' && ip[i] != ':')
                    cuarteto += ip[i];
                else{
                    if (ip[i] == ':'){
                    res[numCuarteto] = stoi(cuarteto);
                    break;
                    }
                    res[numCuarteto] = stoi(cuarteto);
                    cuarteto = "";
                    numCuarteto++;
                }
            }
    }
};

class Heap{     //Estructura utilizada para ordenamiento por Indegree o Outdegree
    int len, maxLen;
    DegreeNode** degreeList;
    int condition;    
    private:
        void swap(int&, int&);  //O(1)
        void bubbleDown(int&);  //O(logn)
    public:
        Heap(int num, int condition){
            this->condition = condition; 
            len = -1;
            maxLen = num;
            degreeList = new DegreeNode*[num+1]; 
            };
        void push(DegreeNode*&);  //O(logn)
        DegreeNode* pop();    //O(logn)
        void save(string);  //O(nlogn)
        void print();   //O(n)
};

void Heap::push(DegreeNode*& node){
    if (len > maxLen)
        throw invalid_argument("Heap overflow");
    else{
        len++;
        degreeList[len] = node;
    }
    int father = (len-1)/2, i = len;

    if (condition == 1)
        while (degreeList[father]->outDegree < degreeList[i]->outDegree)
        {
            swap(father, i);
            i = father;
            father = (i-1)/2;
        }
    else if (condition == 2)
        while (degreeList[father]->inDegree < degreeList[i]->inDegree)
        {
            swap(father, i);
            i = father;
            father = (i-1)/2;
        }
    else
        throw invalid_argument("Opcion no valida");

}

void Heap::bubbleDown(int& father){
    if (father < len)
    {
        int leftChild = (father*2) + 1;
        int rightChild = (father*2) + 2;
        int max = father;
        if (condition == 1)
        {
            if (leftChild < len && degreeList[leftChild]->outDegree > degreeList[father]->outDegree)
            max = leftChild;
            if (rightChild < len && degreeList[rightChild]->outDegree > degreeList[max]->outDegree)
                max = rightChild;    
            if(max != father){
                swap(father, max);
                bubbleDown(max);
            }
        }
        else if (condition == 2)
        {
            if (leftChild < len && degreeList[leftChild]->inDegree > degreeList[father]->inDegree)
            max = leftChild;
            if (rightChild < len && degreeList[rightChild]->inDegree > degreeList[max]->inDegree)
                max = rightChild;    
            if(max != father){
                swap(father, max);
                bubbleDown(max);
            }
        }
    }
}

DegreeNode* Heap::pop(){
    int top = 0;
    DegreeNode* tmp = degreeList[0];
    swap(top, len);
    len--;
    int father = 0;
    bubbleDown(father);
    return tmp;    
}

void Heap::swap(int& father, int& child){
    DegreeNode* aux = degreeList[father];
    degreeList[father] = degreeList[child];
    degreeList[child] = aux;
}

void Heap::print(){
    for (int i = 0; i < len; i++)
    {   
        int value = degreeList[i]->value;
        cout << value << "\t\t" << degreeList[i]->outDegree << "\t\t\t" << degreeList[i]->inDegree << endl;
    }
};

void Heap::save(string fileName){
    ofstream file;
    file.open(fileName);
    file<<"Value\tIndegree\tOutdegree\n";
    while (len>-1)
    {
        DegreeNode* tmp = pop();
        file <<tmp->value<<"\t\t"<<tmp->inDegree<<"\t\t\t"<<tmp->outDegree<<"\n";
    }
    file.close();
}

class Graph{    //Grafo de elementos de subIps

    private: 
        int numVertices;
        int graphNum;
        bool** adjMatrix;
        list<int>* adjList;
        bool* visited;
        void verifyElement(RNode*, set<int>&, queue<Node*>&);
    public:
        Graph(){
            graphNum = 0;
            numVertices = 0;
            adjList = new list<int>[0];
            visited = new bool[0];
        }
        ~Graph(){
            delete []adjList;
            delete []visited;
            delete []adjMatrix;
        }
        void addEdge(int, int); //O(1)
        void printGraph();  //O(n+m)
        void resetVisited(); //O(n+m)

        void matrixInit();  //O(n)
        void loadGraph(string); //O(n)
        void printMatrix(); //O(n^2)
        void saveMatrix();  //O(n^2)
        int InDegree(int);  //O(n)
        int OutDegree(int); //O(n)
        void saveInOutDegree(); //O(n)
        void saveInDegree();    //O(n)
        void saveOutDegree();   //O(n)

};

void Graph::addEdge(int s, int d){
    if (!adjMatrix[s][d])
        this->adjList[s].push_back(d);
}

void Graph::printGraph(){
    resetVisited();
    for (int i = 0; i < graphNum ; i++)
    {
        cout<< "\nVertex " << i << ":";
        for (auto x : this->adjList[i])
            cout<< " -> " << x;
        cout<< endl;
        
    }
}

void Graph::matrixInit(){
    adjMatrix = new bool*[graphNum];
    
    for (int i = 0; i < graphNum; i++)
    {
        adjMatrix[i] = new bool[graphNum];
        for (int j = 0; j < graphNum; j++)
            adjMatrix[i][j] = false;
    }
}

void Graph::printMatrix(){
    cout<<"  ";
    for (int i = 0; i < graphNum; i++)
    cout<<i<<" ";
    cout<<endl;
    for (int i = 0; i < graphNum; i++){
        cout<<i<<"|";
        for (int j = 0; j < graphNum; j++){
            cout << adjMatrix[i][j];
            cout<<" ";
        }
        cout<<"\n";
    }
}

void Graph::saveMatrix(){
    ofstream file;
    file.open("AdjMatrix.csv");
    cout<<endl;
    for (int i = 0; i < graphNum; i++){
        for (int j = 0; j < graphNum; j++)
            file << adjMatrix[i][j] << ",";
        file<<"\n";
    }
    file.close();
}

void Graph::resetVisited(){
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
}

void Graph::verifyElement(RNode* node, set<int> &setGraphs, queue<Node*>& queue){
    int currentIp[4];
    node->IpSection(currentIp);
    int pos1, pos2;
    Node* graphNode;
    for (int i = 0; i < 4; i++)
    {
        if (setGraphs.size() == 0)
            setGraphs.insert(currentIp[i]);
        else
            if (setGraphs.count(currentIp[i]) == 0)
                setGraphs.insert(currentIp[i]);
        if (i<3)
        {
            graphNode = new Node(currentIp[i], currentIp[i+1]);
            queue.push(graphNode);
        }
    }
}

int Graph::InDegree(int nodeValue){
    int count = 0;
    for (int i = 0; i < graphNum; i++)
        if (adjMatrix[i][nodeValue])
            count++;
    return count;
}

int Graph::OutDegree(int nodeValue){
    int count = 0;
    for (int i = 0; i < graphNum; i++)
        if (adjMatrix[nodeValue][i])
            count++;
    return count;
}

void Graph::saveInOutDegree(){
    ofstream file;
    file.open("InOutDegree.txt");
    int inDegree, outDegree;
    file<<"Value\tIndegree\tOutdegree\n";
    for (int i = 0; i < graphNum; i++)
    {
        inDegree = InDegree(i);
        outDegree = OutDegree(i);
        file <<i<<"\t\t"<<inDegree<<"\t\t\t"<<outDegree<<"\n";
    }
    file.close();
}

void Graph::saveOutDegree(){
    Heap heap(graphNum, 1);
    DegreeNode* node;
    int inDegree, outDegree;
    for (int i = 0; i < graphNum; i++)
    {
        inDegree = InDegree(i);
        outDegree = OutDegree(i);
        node = new DegreeNode(i, inDegree, outDegree);
        heap.push(node);
    }
    heap.save("OutDegree.txt");
}

void Graph::saveInDegree(){
    Heap heap(graphNum, 2);
    DegreeNode* node;
    int inDegree, outDegree;
    for (int i = 0; i < graphNum; i++)
    {
        inDegree = InDegree(i);
        outDegree = OutDegree(i);
        node = new DegreeNode(i, inDegree, outDegree);
        heap.push(node);
    }
    heap.save("InDegree.txt");
}


void Graph::loadGraph(string fileName){
    std::ifstream file;
    file.open(fileName);
    string month, day, hour, ip, reason;
    try{
    queue<Node*> queue;
    set<int> setGraphs;
    set<int>::iterator it;
    int pos1, pos2;
    while (file >> month>> day>> hour>> ip)
        {
            getline(file, reason);
            RNode* newNode = new RNode(month, day, hour, ip, reason);
            verifyElement(newNode, setGraphs, queue);
        }
    int max = 0;
    for (auto it = setGraphs.begin(); it!=setGraphs.end();it++)
        if (max < *it)
        max = *it;

    this->graphNum = max+1;
    this->numVertices = setGraphs.size();
    adjList = new list<int>[graphNum];
    visited = new bool[graphNum];
    matrixInit();
    while (queue.size() > 0)
    {   
        Node* current = queue.front();
        queue.pop();
        addEdge(current->n, current->s);
        adjMatrix[current->n][current->s] = true;
    }
    }
    catch(invalid_argument e){
        cerr << e.what() << endl;
    }
}

void readInOutDegreeResults(){
    cout<<"..................................";
    ifstream file;
    string value, inDegree, outDegree;
    file.open("InDegree.txt");
    cout << "\nTop 10 sub Ip con mayor InDegree:\n" << endl;
    file >> value >> inDegree >> outDegree;
    cout << value << "\t\t" << inDegree << "\t" << outDegree << endl;
    for (int i = 0; i < 10; i++)
    {
        file >> value >> inDegree >> outDegree;
        cout << value << "\t\t" << inDegree << "\t\t" << outDegree << endl;
    }
    file.close();
    cout << "\nTop 10 sub Ip con mayor OutDegree:\n" << endl;
    file.open("OutDegree.txt");
    file >> value >> inDegree >> outDegree;
    cout << value << "\t\t" << inDegree << "\t" << outDegree << endl;
    for (int i = 0; i < 10; i++)
    {
        file >> value >> inDegree >> outDegree;
        cout << value << "\t\t" << inDegree << "\t\t" << outDegree << endl;
    }

}

/*
Lectura de archivo bitacora (4).txt
Alamacenamiento de matriz de adyacencia obtenida en AdjMatrix.csv para analisis de desarrollo
Almacenamiento de las subIps en InOutDegree.txt (Contiene el InDegree y OutDegree ordenado por valor de subIp)
Almacenamiento de las subIps en InDegree.txt (Contiene el InDegree y OutDegree ordenado por InDegree)
Almacenamiento de las subIps en OutDegree.txt (Contiene el InDegree y OutDegree ordenado por OutDegree)
Impresion de Top 10 subIp con maximo valor InDegree
Impresion de Top 10 subIp con maximo valor OutDegree
*/
int main(){
    Graph g;
    g.loadGraph("bitacora (4).txt");
    g.saveMatrix(); //Almacenado en AdjMatrix.txt
    cout << "\nAnalizando Indegree, Outdegree...\n";
    g.saveInOutDegree();    //Almacenado en InOutDegree.txt
    cout << "\nArchivo Indegree, Outdegree completo\n";
    g.saveOutDegree();      //Almacenado en OutDegree.txt
    cout << "\nArchivo Outdegree completo\n";
    g.saveInDegree();       //Almacenado en InDegree.txt
    cout << "\nArchivo Indegree completo\n";
    readInOutDegreeResults();

    return 0;
}