#include <iostream>

using namespace std;

#define V 5 // Total vertices in the graph
#define INF 999999

// Helper to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];    // dist[i] will hold the shortest distance from src to i
    bool sptSet[V]; // sptSet[i] is true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it's not in sptSet, there is an edge, and total 
            // weight of path from src to v through u is smaller than current dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    /* Example Graph
          10       3
    (0)------(1)------(2)
     |      / | \      |
    5|    2/  |1 \8    |9
     |    /   |   \    |
    (3)-------(4)-------
          2             */
          
    int graph[V][V] = { { 0, 10, 0, 5, 0 },
                        { 0, 0, 1, 2, 2 },
                        { 0, 0, 0, 0, 4 },
                        { 0, 3, 0, 0, 2 },
                        { 7, 0, 6, 0, 0 } };

    dijkstra(graph, 0);

    return 0;
}