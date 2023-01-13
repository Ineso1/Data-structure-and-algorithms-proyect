#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

class Graph {
    private: 
    int numVertices;
    list<int> *adjList;
    bool *visited;
    void topologicalSort(int, stack<int>&);

    public:
    Graph(int v){
        numVertices = v;
        adjList = new list<int>[v];
        visited = new bool[v];
    }
    ~Graph(){
        delete []adjList;
        delete []visited;
    }
    void addEdge(int, int);
    void printGraph();
    void resetVisited();

    void DFS(int);
    void BFS(int);

    bool isBipartite(int);
    
    void topologicalSort();
    void isTree();

};

void Graph::resetVisited(){
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
}

void Graph::addEdge(int s, int d){
    this->adjList[s].push_back(d);
    this->adjList[d].push_back(s);
}

void Graph::printGraph(){
    for (int i = 0; i < this->numVertices ; i++)
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

void Graph::topologicalSort(int vertex, stack<int> &stack){
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjList[vertex];

    /**/
    for(auto i: adjVertex)
    if(!this->visited[i]){
        topologicalSort(i, stack);
            stack.push(i);
        }
}

void Graph::topologicalSort(){
    stack<int> stack;
    topologicalSort(0, stack);
    for (int i; i < stack.size(); i++)
    {
        cout<<stack.top()<< " ";
        stack.pop();
    }
}

int main(){
    Graph G(5);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(0, 3);
    G.addEdge(1, 2);
    G.addEdge(2, 4);

    G.printGraph();
    G.resetVisited();

    cout<< "\nDFS: ";
    G.DFS(1);

    G.resetVisited();

    cout << "\nBFS";
    G.BFS(0);

    return 0;
}