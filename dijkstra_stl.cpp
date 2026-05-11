#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

// Graph class
class Graph {
public:

    int V;

    // adjacency list:
    // adj[u] = { {v, weight}, {v, weight} ... }
    vector<vector<pair<int, int>>> adj;

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add directed edge
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    void dijkstra(int source) {

        // Distance array
        vector<int> dist(V, INF);

        // Min Heap
        // pair = {distance, vertex}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[source] = 0;

        pq.push({0, source});

        while (!pq.empty()) {

            int currentDist = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            // Ignore outdated entries
            if (currentDist > dist[u]) {
                continue;
            }

            // Traverse neighbors
            for (auto edge : adj[u]) {

                int v = edge.first;
                int weight = edge.second;

                // Relaxation
                if (dist[u] + weight < dist[v]) {

                    dist[v] = dist[u] + weight;

                    pq.push({dist[v], v});
                }
            }
        }

        // Print shortest distances
        cout << "Vertex\tDistance from Source\n";

        for (int i = 0; i < V; i++) {
            cout << i << "\t" << dist[i] << endl;
        }
    }
};

int main() {

    Graph g(5);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);

    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);

    g.addEdge(2, 3, 4);

    g.addEdge(3, 0, 7);
    g.addEdge(3, 2, 6);

    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 9);
    g.addEdge(4, 3, 2);

    g.dijkstra(0);

    return 0;
}