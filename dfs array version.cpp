#include <iostream>
using namespace std;


class Graph{
    int **adj;
    int V;
    int *deg;
public:
    Graph(int Vertices){
        V = Vertices;

        adj = new int*[V];
        for (int i=0; i<Vertices; i++){
            adj[i] = new int[V];
        }
        
        deg = new int[V];
        
        for (int i=0; i<Vertices; i++){
            deg[i] = -1;
        }
    }
    
    void addEdge(int u, int v){
        adj[u][deg[u]] = v;
        adj[v][deg[v]] = u;
        deg[u]++; deg[v]++;
    }

    void dfsutil(int u, int visited[]){
        visited[u] = 1;
        cout<<u<<" ";

        for (int i=0; i<deg[u]; i++){
            int v = adj[u][i];
            if (!visited[i]){
                dfsutil(v, visited );
            }
        }
    }
    void dfs(int s){
        int visited[V] = {0};
        dfsutil(s, visited); 
    }
};

int main(){
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(2,0);
    g.dfs(2);
    return 0;
}