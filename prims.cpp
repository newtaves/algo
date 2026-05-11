#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
// first = weight
// second = vertex

class Graph {
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // undirected graph
    }

    void primMST() {
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        vector<bool> visited(V, false);

        int totalCost = 0;

        // Start from vertex 0
        pq.push({0, 0});

        cout << "Edges in MST:\n";

        while (!pq.empty()) {
            int weight = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Skip if already included
            if (visited[u])
                continue;

            visited[u] = true;
            totalCost += weight;

            cout << "Included Vertex: " << u
                 << " with edge weight " << weight << endl;

            // Traverse neighbors
            for (auto neighbor : adj[u]) {
                int w = neighbor.first;
                int v = neighbor.second;

                if (!visited[v]) {
                    pq.push({w, v});
                }
            }
        }

        cout << "\nTotal MST Cost = " << totalCost << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
}