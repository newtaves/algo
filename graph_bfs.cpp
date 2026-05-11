#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node *next;

    Node(int val): data(val), next(nullptr) {}
};


class Queue {
public:
    Node *front;
    Node *rear;

    Queue(){front = rear =nullptr;}

    bool is_empty() { return front == nullptr;}

    void enqueue(int x) {
        Node *temp = new Node(x);

        if (is_empty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue() {
        if (is_empty()) {return -1;}
        Node *temp = front;
        int val = temp->data;
        front = front->next;
        if (front==nullptr) { rear = nullptr;}
        delete temp;
        return val;
    }
};




class Graph {
    Node **adj;
    int n;
public:
    void createGraph(int vertices) {
        n = vertices; 
        adj = new Node*[n];
        for (int i=0; i<n; i++) {
            adj[i] = nullptr;
        }
    }


    void add_edge(int u, int v) {
        //u(index)-->v()list

        //create the new node
        Node *newNode = new Node(v);
        //new node points the previous value i.e. adj[u]
        newNode->next = adj[u];
        //adj[u] points to the new Node
        adj[u] = newNode;
    }

    void display() {
        for (int i = 0; i<n; i++) {
            Node *temp = adj[i];
            if (temp!=nullptr) {
                cout<<i<<"--> ";
                while (temp !=nullptr) {
                    cout<<temp->data<<" ";
                    temp = temp->next; 
                }
                cout<<endl;
            }
        }
    }


    void bfs(int s) {
        int *visited = new int[n]();
        visited[s] = 1; //add s to discovered node;

        Queue q;
        q.enqueue(s);

        while (!q.is_empty()) {
            int cur = q.dequeue();
            cout<<cur<<" ";
            Node *temp = adj[cur];
            while (temp!=nullptr) {
                if (visited[temp->data] !=1 ) {
                    q.enqueue(temp->data);
                    visited[temp->data] = 1;
                }
                temp=temp->next;
            }
        }

    }
};


int main()
{
    Graph g;

    int choice;
    int n;
    int u,v;
    int start;

    while(true)
    {
        cout<<"\n----- MENU -----\n";
        cout<<"1. Create Graph\n";
        cout<<"2. Display Graph\n";
        cout<<"3. BFS Traversal\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";

        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter number of vertices: ";
                cin>>n;
                g.createGraph(n);
                cout<<"Enter edges (u v). Enter -1 -1 to stop:\n";

                while(true)
                {
                    cin>>u>>v;

                    if(u==-1 && v==-1)
                        break;

                    g.add_edge(u,v);
                }
                break;

            case 2:
                cout<<"\nAdjacency List:\n";
                g.display();
                break;

            case 3:
                cout<<"Enter starting vertex: ";
                cin>>start;

                cout<<"BFS Traversal: ";
                g.bfs(start);
                cout<<endl;
                break;

            case 4:
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
}