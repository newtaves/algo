#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

class Graph {
    int V;
    vector<vector<pii>> adj;
public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void add_edge(int u, int v, int w) {
        adj[u].push_back(pii(w, v));
        adj[v].push_back(pii(w, u));
    }

    int prims() {
        vector<int> mst_set(V, 0);
        int mst = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, 0}); // 
        
        while (pq.size()>0) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if (!mst_set[u]) {
                mst_set[u] = 1;
                cout<<"Including "<<u<<", ";
                mst += wt;
                cout<<"weight "<<wt<<" "<<mst<<endl;

                for (pii t: adj[u]) {
                    pq.push(t);
                }
            }   
        }
        return mst;
    } 
};

int main() {
    Graph g(6);
    g.add_edge(0,1,10);
    g.add_edge(0,2,30);
    g.add_edge(0,3,15);
    g.add_edge(1,3,40);
    g.add_edge(2,3,50);

    cout<<g.prims()<<endl;


    return 0;
}