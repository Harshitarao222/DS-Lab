#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;                           
    vector<vector<int>> adjList;    
    vector<vector<int>> adjMatrix;   
    bool directed;

public:
    Graph(int V, bool directed = false) {
        this->V = V;
        this->directed = directed;
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
     
        adjList[u].push_back(v);

        
        adjMatrix[u][v] = 1;

        if (!directed) {
            adjList[v].push_back(u);
            adjMatrix[v][u] = 1;
        }
    }

    void displayAdjList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    int outDegree(int u) {
        return adjList[u].size();
    }

    int inDegree(int u) {
        int count = 0;
        for (int i = 0; i < V; i++)
            if (adjMatrix[i][u] == 1)
                count++;
        return count;
    }

    void adjacentVertices(int u) {
        cout << "Adjacent vertices of " << u << ": ";
        for (int v : adjList[u])
            cout << v << " ";
        cout << endl;
    }

    int countEdges() {
        int count = 0;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (adjMatrix[i][j] == 1)
                    count++;

       
        return directed ? count : count / 2;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    int directedChoice;
    cout << "Is the graph directed? (1=yes, 0=no): ";
    cin >> directedChoice;

    Graph g(V, directedChoice);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayAdjList();
    g.displayAdjMatrix();

    int node;
    cout << "\nEnter vertex to find in/out degree: ";
    cin >> node;
    cout << "Out-degree of " << node << ": " << g.outDegree(node) << endl;
    cout << "In-degree of " << node << ": " << g.inDegree(node) << endl;

    cout << "\nEnter vertex to list adjacent vertices: ";
    cin >> node;
    g.adjacentVertices(node);

    cout << "\nTotal edges in graph: " << g.countEdges() << endl;

    return 0;
}