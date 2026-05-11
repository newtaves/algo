#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node*next;

    Node(int val) : data(val), next(nullptr) {}
};


class graph {
public:
    Node **adj;
    int n; //number of vertices

    graph(int n){
        this->n = n;
        adj = new Node*[n];

        for (int i =0; i<n; i++) {
            adj[i] = nullptr;
        }
    }

    void add_edge(int u, int v) {
        //edge from u to v i.e. u-->v and v-->u
        Node *newNode = new Node(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        Node *newNode2 = new Node(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    void _dfs(int*visited,  int src) {
        cout<<src<<" ";
        visited[src] = 1;
        
        Node* temp = adj[src];
        while (temp != nullptr) {
            if (!visited[temp->data] ) {
                _dfs(visited, temp->data);
            }
            temp = temp->next;
        }
    }

    void dfs() {
        int *visited = new int[n]();

        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                _dfs(visited, i);
            }
        }
    }
};


int main() {

    graph g(5);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);

    g.dfs();

    return 0;
}