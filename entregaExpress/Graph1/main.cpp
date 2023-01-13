#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <set>
using namespace std;

class Node{
    public:
    int n, s;
    Node(int n, int s){
        this->n = n;
        this->s = s;
    };
};

class Graph {
    private: 
    int numVertices;
    int graphNum;
    bool** adjMatrix;
    list<int> *adjList;
    bool *visited;

    void DFS(int, bool);

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

    void addEdge(int, int);
    void printGraph();
    void resetVisited();

    void matrixInit();
    void loadGraph(string);
    void printMatrix();

    void BFS(int);
    void DFS(int);

};

//Inicializa matriz a partir de la cantidad de grafos detectados
//O(n2)
void Graph::matrixInit(){
    adjMatrix = new bool*[graphNum];
    for (int i = 0; i < graphNum; i++)
    {
        adjMatrix[i] = new bool[graphNum];
        for (int j = 0; j < graphNum; j++)
            adjMatrix[i][j] = false;
    }
}

//Impresion de matriz de adyacencia
//O(n2)
void Graph::printMatrix(){
    for (int i = 0; i < graphNum; i++){
        for (int j = 0; j < graphNum; j++){
            cout << adjMatrix[i][j];
            cout<<" ";
        }
        cout<<"\n";
    }
}


//LLenado de grafos a partir de un txt
//O(n)
void Graph::loadGraph(string fileName){
    ifstream file;
    int pos1, pos2;
    file.open(fileName);
    queue<Node*> queue;
    set<int> setGraphs;
    set<int>::iterator it;
    Node* node;
    while (file >> pos1 >> pos2)
    {   
        if (setGraphs.size() == 0)
        {
            if (pos1 != pos2)
            {
                setGraphs.insert(pos1);
                setGraphs.insert(pos2);
            }
            else
                setGraphs.insert(pos1);
        }
        else{
            if (setGraphs.count(pos1) == 0)
                setGraphs.insert(pos1);
            if (setGraphs.count(pos2) == 0)
                setGraphs.insert(pos2);
            
        }

        node = new Node(pos1, pos2);
        queue.push(node);
    }

    int max = 0;
    for (auto it = setGraphs.begin(); it!=setGraphs.end();it++)
        if (max < *it)
        max = *it;

    this->graphNum = max+1;
    this->numVertices = setGraphs.size();
    adjList = new list<int>[numVertices];
    visited = new bool[numVertices];
    //cout<<"Elementos de set "<<setGraphs.size()<<endl;
    matrixInit();
    while (queue.size() > 0)
    {   
        Node* current = queue.front();
        queue.pop();
        adjMatrix[current->n][current->s] = true;
        addEdge(current->n, current->s);
    }
}

//Reset de lista boleana de visitas
//O(n)
void Graph::resetVisited(){
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
}

//Agregar enlace de grafo
//O(1)
void Graph::addEdge(int s, int d){
    this->adjList[s].push_back(d);

}

//Impresion de lista de adyacencia
//O(n)
void Graph::printGraph(){
    resetVisited();
    for (int i = 0; i < this->numVertices ; i++)
    {
        cout<< "\nVertex " << i << ":";
        for (auto x : this->adjList[i])
            cout<< " -> " << x;
        cout<< endl;
        
    }
}

//Busqueda de todos los grafos por profundidad
//O(n)
void Graph::DFS(int vertex, bool t){
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjList[vertex];
    cout<< vertex << " ";
    for(auto i: adjVertex)
    if(!this->visited[i])
        DFS(i,t);
}

void Graph::DFS(int startVertex){
    resetVisited();
    cout << "\nDFS  start vertex ("<< startVertex<<") :\n";
    DFS(startVertex, true);
    cout << "\n\n";
}

//Busqueda de todos los grafos por altura
//O(n)
void Graph::BFS(int startVertex){
    resetVisited();
    visited[startVertex] = true;
    list<int> queue;
    queue.push_back(startVertex);
    cout << "\nBFS  start vertex ("<< startVertex<<") :\n";
    while(!queue.empty()){
        int currVertex = queue.front();
        cout<< currVertex << " ";
        queue.pop_front();

        for (auto i: adjList[currVertex])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
    cout<< endl;
}



int main(){
    
    //Caso de prueba 2
    Graph G;
    G.loadGraph("Prueba2.txt");
    cout << "\n............Matriz Adyacencia..........." <<endl;
    G.printMatrix();
    G.printGraph();
    cout << "\n............Prueba BFS..........." <<endl;
    G.BFS(0);
    G.BFS(1);
    G.BFS(2);
    G.BFS(3);
    G.BFS(4);
    G.BFS(5);
    G.BFS(6);
    G.BFS(7);
    G.BFS(8);
    G.BFS(9);
    G.BFS(10);
    cout << "\n............Prueba DFS..........." <<endl;
    G.DFS(0);
    G.DFS(1);
    G.DFS(2);
    G.DFS(3);
    G.DFS(4);
    G.DFS(5);
    G.DFS(6);
    G.DFS(7);
    G.DFS(8);
    G.DFS(9);
    G.DFS(10);
    
    /* 
    //Caso de prueba1
    Graph G;
    G.loadGraph("Prueba.txt");
    cout << "\n............Matriz Adyacencia..........." <<endl;
    G.printMatrix();
    G.printGraph();
    cout << "\n............Prueba BFS..........." <<endl;
    G.BFS(0);
    G.BFS(1);
    G.BFS(2);
    G.BFS(3);
    G.BFS(4);
    G.BFS(5);

    cout << "\n............Prueba DFS..........." <<endl;
    G.DFS(0);
    G.DFS(1);
    G.DFS(2);
    G.DFS(3);
    G.DFS(4);
    G.DFS(5);

    */

    return 0;
}