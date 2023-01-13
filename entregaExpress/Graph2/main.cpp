#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
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

class Graph{
    private: 
    int numVertices;
    int graphNum;
    bool** adjMatrix;
    list<int>* adjList;
    bool* visited;
    void DFS(int, bool);
    void topologicalSort(int);
	bool isCyclic(int, int);
    

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
    bool isBipartite(int);
    void topologicalSort();
    bool isTree();
    

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


bool Graph::isBipartite(int startVertex){
    vector<bool> color(numVertices);
    
    visited[startVertex] = true;
    color[startVertex] = 0;

    list<int>queue;
    queue.push_back(startVertex);

    while (!queue.empty())
    {
        int v = queue.front();
        queue.pop_front();
        for (auto u: adjList[v])
        {
            if(!visited[u] == true){
                visited[u] = true;
                color[u] = !color[v];

                queue.push_back(u);
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}

//Besca apartir de una busqueda en profundidas los elementos por orden topologico recursivamente
//O(n + m)
void Graph::topologicalSort(int vertex){
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjList[vertex];
    for(auto i: adjVertex){
        if(!this->visited[i]){
            topologicalSort(i);
        }
    }
    cout<<vertex<<" ";
}

void Graph::topologicalSort(){
    resetVisited();
    for (int i = 0; i < graphNum; i++){
        if(!this->visited[i])
            topologicalSort(i);
    }
    cout<<endl;
}

//Busqueda de ciclos dentro del grafo
//O(n + m)
bool Graph::isCyclic(int vertexNum, int parent)
{
	visited[vertexNum] = true;
	for (auto i: adjList[vertexNum])
	{
		if (!visited[i])
		{
		if (isCyclic(i, vertexNum))
			return true;
		}
		else if (i != parent)
		return true;
	}
	return false;
}

//Busqueda de ciclos dentro del grafo
//O((n + m)2)
bool Graph::isTree(){

	resetVisited();
	if (isCyclic(0, -1))
			return false;
	for (int i = 0; i < graphNum; i++)
		if (!visited[i])
		return false;
	return true;
}

int main(){
    //Caso de prueba 
    string casos [4];
    casos[0] = "Prueba.txt";
    casos[1] = "Prueba2.txt";
    casos[2] = "Prueba3.txt";
    casos[3] = "Prueba4.txt";

        Graph G;
        G.loadGraph(casos[2]);
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
        cout<< "\nEs bipartita? " << G.isBipartite(0)<<endl;
        cout<<"topological sort: ";
        G.topologicalSort();
        cout<<"Es arbol: "<<G.isTree();
        return 0;

}