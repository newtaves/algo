#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node *next;
    Node(int val): data(val), next(nullptr) {};
};

class Stack{
public:    
    Node* top;
    Stack() {
        top = nullptr;
    }

    bool is_empty() {
        return top == nullptr;
    }

    void push(int val) {

        Node *newNode = new Node(val);

        newNode->next = top;

        top = newNode;
    }

    int pop() {

        if (is_empty())
            return -1;

        Node *temp = top;

        int cur = temp->data;

        top = top->next;

        delete temp;

        return cur;
    }
};



class Graph{
public:
    Node **adj;
    int n; //number of vertices

    void createGraph(int vertices) {
        n = vertices;
        adj = new Node*[n];

        for (int i=0;i <n; i++) {
            adj[i] = nullptr;
        }
    }

    void add_edge(int u, int v) {
        // adj[u] --> v
        //first create a new Node
        Node *newNode = new Node(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    void display() {
        for (int i=0; i<n; i++) {
            cout<< i <<"-->";
            Node *temp = adj[i];
            while (temp != nullptr) {
                cout<< temp->data <<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    void dfs(int start) {
        int *visited = new int[n]();
        visited[start] = 1;
        
        Stack s;
        s.push(start);
        while (!s.is_empty()) {
            int u = s.pop();
            cout<<u<<" ";

            Node*temp = adj[u];
            while (temp) {
                //if not visisted the add it in stack and mark viisted
                if (visited[temp->data]!=1) {
                    s.push(temp->data);
                    visited[temp->data] = 1;
                }
                temp = temp->next;
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
        cout<<"3. DFS Traversal\n";
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

                cout<<"DFS Traversal: ";
                g.dfs(start);
                cout<<endl;
                break;

            case 4:
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
}