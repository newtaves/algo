#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 9999999

class Edge {
public:    

    int v, wt;
    Edge(int ver, int w) : v(ver), wt(w) {}
};

void dijkstra(int src, vector<vector<Edge>> g, int V) {
    cout<<"test1";

    vector<int> dist(V, INF);
    dist[src] = 0;

    priority_queue<
    pair<int, int>,
    vector<pair<int,int>>,
    greater<pair<int, int>>
    > pq;

    cout<<"test2";

    pq.push({0, src});

    while (pq.size()>0) {
        int u = pq.top().second;
        pq.pop();

        for (Edge e: g[u]) {
            if (dist[e.v] > dist[u]+ e.wt) {
                dist[e.v] = dist[u]+ e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }
cout<<"test3";
    for (int i = 0; i<V; i++) {
        cout<<i<<" : "<<dist[i]<<endl;
    }
    cout<<"test4";
}


int main() {

    cout<<"running";
    vector<vector<Edge>> g(6);
    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));
    
    g[4].push_back(Edge(3, 2));
    g[5].push_back(Edge(5, 5));

    cout<<"test0";

    dijkstra(0, g, 6);

    cout<<"testfinal";
    return 0;
}