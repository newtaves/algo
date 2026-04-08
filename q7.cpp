#include <iostream>
#include "linkedlistadt.cpp"

using namespace std;

class Queue
{
    Node *front, *rear;

public:

    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void enqueue(int x)
    {
        Node* temp = new Node(x);

        if(rear == NULL)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    int dequeue()
    {
        Node* temp = front;
        int x = temp->data;

        front = front->next;

        if(front == NULL)
            rear = NULL;

        delete temp;
        return x;
    }
};

class Graph
{
    int n;
    LinkedList adj[20];

public:

    void createGraph(int vertices)
    {
        n = vertices;
    }

    void addEdge(int u,int v)
    {
        adj[u].insertEnd(v);
        adj[v].insertEnd(u);
    }

    void display()
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<" -> ";
            adj[i].display();
            cout<<endl;
        }
    }

    void BFS(int s)
    {
        int visited[20]={0};

        Queue q;
        q.enqueue(s);
        visited[s]=1;

        while(!q.isEmpty())
        {
            int u = q.dequeue();
            cout<<u<<" ";

            Node* temp = adj[u].getHead();

            while(temp!=NULL)
            {
                int v = temp->data;

                if(!visited[v])
                {
                    visited[v]=1;
                    q.enqueue(v);
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

                    g.addEdge(u,v);
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
                g.BFS(start);
                cout<<endl;
                break;

            case 4:
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
}