#include <iostream>
#include <list>
#include <vector>

using namespace std;

// struct Node
// {
//     int vertex;
//     struct Node *next;
// };

// struct Graph
// {
//     int numVertices;
//     struct Node **adjLists;
// };

class Graph
{
private:
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V)
    {
        numVertices = V;
        adjLists = new list<int>[V];
        visited = new bool[V];
    }

    ~Graph()
    {
        delete[] adjLists;
        delete[] visited;
    }

    void addEdge(int, int);
    void printGraph();
    void ResetVisited();

    void DFS(int);
    void BFS(int);
    bool isBipartite(int);
};

void Graph::addEdge(int s, int d)
{
    this->adjLists[s].push_back(d);
    this->adjLists[d].push_back(s);
}

void Graph::printGraph()
{
    for (int i = 0; i < this->numVertices; i++)
    {
        cout << "\nVertex " << i << ":";
        for (auto x : this->adjLists[i])
            cout << " -> " << x;
        cout << endl;
    }
}

void Graph::ResetVisited()
{
    for (int i = 0; i < this->numVertices; i++)
        this->visited[i] = false;
}

//  DFS Function complexity - O(V + E) - Space Complexity O(V)
void Graph::DFS(int vertex)
{
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjLists[vertex];

    cout << vertex << " ";

    for (auto i : adjVertex)
        if (!this->visited[i])
            DFS(i);
}

void Graph::BFS(int startVertex)
{
    visited[startVertex] = true;

    list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty())
    {
        int currVertex = queue.front();

        cout << currVertex << " ";

        queue.pop_front();

        for (auto i : adjLists[currVertex])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

bool Graph::isBipartite(int startVertex)
{
    vector<bool> color(numVertices);

    visited[startVertex] = true;
    color[startVertex] = 0;

    list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty())
    {
        int v = queue.front();
        queue.pop_front();

        for (auto u : adjLists[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                color[u] = !color[v];

                queue.push_back(u);
            }
            else if (color[v] == color[u])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    g.ResetVisited();

    cout << "\nDFS: ";
    g.DFS(1);

    g.ResetVisited();

    cout << "\n\nBFS: ";
    g.BFS(0);

    g.ResetVisited();

    cout << "\n\nIs Bipartite? ";
    if (g.isBipartite(0))
        cout << "Grapg is Bipartite";
    else
        cout << "Graph is not Bipartite";

    return 0;
}