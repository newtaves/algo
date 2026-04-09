#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next = NULL;
    }
};

class LinkedList{
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }
    void insertEnd(int x){
        Node* value = new Node(x);
        if (head == NULL){
            head = value;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL){
            temp=temp->next;
        }
        temp->next = value;
    }
};

class Queue{
    Node *front, *rear;
public:
    Queue(){
        front=rear=NULL;
    }
    bool isEmpty(){
        return front ==NULL;
    }
    void enqueue(int x){
        Node* element = new Node(x);
        if (isEmpty()){
            front=rear=element;
            return;
        }
        rear->next = element;
        rear=rear->next;
        return;
    }
    int dequeue(){
            if (!isEmpty()){
            int data = front->data;
            Node*temp = front;
            front = front->next;
            if (front==NULL){
                front=rear=NULL;
            }
            delete temp;
            return data;
        }
        return -1;
    }
};


class Graph {
    int V;
    int** adj;
    int* deg;
public:
    Graph(int V){
        this->V = V;
        adj = new int*[V];
        for (int i =0; i<V; i++){
            adj[i] = new int[V];
        }
        deg = new int[V];
        for (int i =0; i<V; i++){
            deg[i] = 0;
        }
    };
    void addEdge(int u, int v){
        adj[u][deg[u]] = v;
        adj[v][deg[v]] = u;
        deg[u]++;
        deg[v]++;
    }
    void display(){
        for (int i =0; i<V; i++){
            cout<<i<<": ";
            for (int j = 0; j < deg[i]; j++){
                cout << adj[i][j] << " ";
            }
            cout<<endl;
        }
    }

    void bfs(int start){
        int* visited = new int[this->V]{0};
        Queue q;
        q.enqueue(start);
        visited[start] = 1;
        while (!q.isEmpty()){
            int u = q.dequeue();
            cout<<u<<" ";
            int temp = 0;
            while (temp!= deg[u]){
                if (!visited[adj[u][temp]]){
                    q.enqueue(adj[u][temp]);
                    visited[adj[u][temp]] = 1;
                }
                temp++;
            }
        }

    }
};
// int main(){
//     cout<<"stated"<<endl;
//     Graph g(5);
//     g.addEdge(1,2);
//     g.addEdge(1,0);
//     g.addEdge(1,1);
//     g.addEdge(1,3);
//     g.addEdge(1,4);
//     g.display();

//     return 0;
// }

int main(){
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(2,0);
    g.bfs(2);

}