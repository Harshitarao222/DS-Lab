#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);  
        adj[v].push_back(u);
    }

    void DFSUtil(int node) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                DFSUtil(neighbour);
            }
        }
    }

    void DFS(int start) {
        fill(visited.begin(), visited.end(), false);
        cout << "DFS Traversal: ";
        DFSUtil(start);
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    g.DFS(start);

    return 0;
}