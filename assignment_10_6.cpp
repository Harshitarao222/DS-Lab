#include <iostream>

#include <vector>

using namespace std;



#define INF 999999



int findMinVertex(vector<int> &dist, vector<bool> &visited, int V) {

    int minDist = INF, minIndex = -1;



    for (int v = 0; v < V; v++) {

        if (!visited[v] && dist[v] < minDist) {

            minDist = dist[v];

            minIndex = v;

        }

    }

    return minIndex;

}



void Dijkstra(vector<vector<int>> &graph, int V, int src) {

    vector<int> dist(V, INF);

    vector<bool> visited(V, false);



    dist[src] = 0;



    for (int i = 0; i < V - 1; i++) {

        int u = findMinVertex(dist, visited, V);

        visited[u] = true;



        for (int v = 0; v < V; v++) {

            if (graph[u][v] && !visited[v] &&

                dist[u] + graph[u][v] < dist[v]) {



                dist[v] = dist[u] + graph[u][v];

            }

        }

    }



   

    cout << "\nShortest distances from source " << src << ":\n";

    for (int i = 0; i < V; i++) {

        cout << "To vertex " << i << " = " << dist[i] << endl;

    }

}



int main() {

    int V;

    cout << "Enter number of vertices: ";

    cin >> V;



    vector<vector<int>> graph(V, vector<int>(V));



    cout << "Enter adjacency matrix (0 if no edge):\n";

    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

            cin >> graph[i][j];

        }

    }



    int src;

    cout << "Enter source vertex: ";

    cin >> src;



    Dijkstra(graph, V, src);



    return 0;

}