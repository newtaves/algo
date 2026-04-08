//Display the data stored in a given graph using the Depth-First algorithm
#include <iostream>
#include "linkedlistadt.cpp"
using namespace std;


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

    void DFSUtil(int u, int visited[])
    {
        visited[u]=1;
        cout<<u<<" ";

        Node* temp = adj[u].getHead();

        while(temp!=NULL)
        {
            int v = temp->data;

            if(!visited[v])
            {
                DFSUtil(v, visited);
            }

            temp=temp->next;
        }
    }

    void DFS(int s)
    {
        int visited[20]={0};
        DFSUtil(s, visited);
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

                cout<<"DFS Traversal: ";
                g.DFS(start);
                cout<<endl;
                break;

            case 4:
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
}