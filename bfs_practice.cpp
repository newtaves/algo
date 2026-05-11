#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue{
    Node *front, *rear;
public:
    Queue(): front(nullptr), rear(nullptr) {}

    bool empty() {
        return front==nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (empty()) {
            front=newNode;
            rear=newNode;
        }else {
            rear->next = newNode;
            rear=rear->next;
        }
    }

    int dequeue() {
        if (empty()){return -1;}
        Node *temp = front;
        int output = temp->data;
        front = front->next;
        if (front==nullptr) {
            rear = nullptr;
        }
        delete temp;
        return output;
    }
};


class graph{
    Node **adj;  //the adjacency List
    int V; //number of vertices
public:
    graph(int v){
        this->V = v;
        adj = new Node*[V];
        for (int i=0; i<v; i++) {
            adj[i] = nullptr;
        }
    }

    ~graph() {
        for ( int i =0;i<V; i++) {
            delete adj[i];
        }
        delete adj;
    }

    void add_edge(int u, int v) {
        Node* newNode = new Node(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    void bfs(int start) {
        int *visited = new int[V]();
        Queue q;
        q.enqueue(start);
        visited[start] = 1;

        while (!q.empty())
        {
            int t = q.dequeue();
            cout<<t<<" ";

            Node* temp = adj[t];
            while (temp) {
                int curNode = temp->data;
                if (!visited[curNode]) {
                    q.enqueue(curNode);
                    visited[curNode] = 1;
                }
            temp = temp->next;
            }
        }
        
    }
};


int main() {
    graph g(5);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(1,0);
    g.add_edge(0, 2);

    g.bfs(1);


    return 0;
}