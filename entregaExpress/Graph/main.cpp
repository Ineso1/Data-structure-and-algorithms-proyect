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

class Graph{
    private:
        bool** adjMatrix;
        list<int> *adjList;
        bool *visited;
        int graphNum;
        

    public:
        Graph(){ 
            graphNum = 0;
            adjList = new list<int>[graphNum];
            visited = new bool[graphNum];
            matrixInit();
        };
        ~Graph(){
        delete []adjList;
        delete []visited;
        delete adjMatrix;
        }
        void addEdge(int, int);
        void printGraph();
        void resetVisited();
        void matrixInit();
        void fillMatrix(string);
        void addEdge(int, int);
        void loadGraph(int);
        void printMatrix();
        void DFS(int);
        void BFS(int);
        

};

void Graph::fillMatrix(string fileName){
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
    cout<<"Elementos de set "<<setGraphs.size()<<endl;
    matrixInit();
    while (queue.size() > 0)
    {   
        Node* current = queue.front();
        queue.pop();
        adjMatrix[current->n][current->s] = true;
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

void Graph::loadGraph(int graphNum){
    this->graphNum = graphNum;
    matrixInit();
}

void Graph::printMatrix(){
    for (int i = 0; i < graphNum; i++){
        for (int j = 0; j < graphNum; j++){
            cout << adjMatrix[i][j];
            cout<<" ";
        }
        cout<<"\n";
    }
}

void Graph::addEdge(int s, int d){
    this->adjList[s].push_back(d);
    this->adjList[d].push_back(s);
}

void Graph::printGraph(){
    for (int i = 0; i < this->graphNum ; i++)
    {
        cout<< "\nVertex" << i << ";";
        for (auto x : this->adjList[i])
            cout<< "-> " << x;
        cout<< endl;
        
    }
}

void Graph::DFS(int vertex){
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjList[vertex];

    cout<< vertex << endl;
    for(auto i: adjVertex)
    if(!this->visited[i])
        DFS(i);
}

void Graph::BFS(int startVertex){
    visited[startVertex] = true;
    list<int> queue;
    queue.push_back(startVertex);

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
}

int main(){
    Graph g;
    //g.loadGraph(2);
    g.fillMatrix("Prueba.txt");
    g.printMatrix();
    return 0;
}