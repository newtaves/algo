#include <iostream>
using namespace std;

const int INF = 1000000000;

// ================= NODE FOR ADJACENCY LIST =================
class Node {
public:
    int vertex;
    int weight;
    Node* next;

    Node(int v, int w) {
        vertex = v;
        weight = w;
        next = nullptr;
    }
};

// ================= MIN HEAP NODE =================
class HeapNode {
public:
    int vertex;
    int dist;

    HeapNode() {
        vertex = 0;
        dist = 0;
    }

    HeapNode(int v, int d) {
        vertex = v;
        dist = d;
    }
};

// ================= MIN HEAP =================
class MinHeap {
public:
    HeapNode* arr;
    int size;
    int capacity;

    MinHeap(int cap) {
        capacity = cap;
        size = 0;

        arr = new HeapNode[capacity];
    }

    // Swap two heap nodes
    void swapNodes(HeapNode& a, HeapNode& b) {
        HeapNode temp = a;
        a = b;
        b = temp;
    }

    // Heapify upward
    void heapifyUp(int index) {

        while (index > 0) {

            int parent = (index - 1) / 2;

            if (arr[parent].dist > arr[index].dist) {
                swapNodes(arr[parent], arr[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    // Heapify downward
    void heapifyDown(int index) {

        while (true) {

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int smallest = index;

            if (left < size &&
                arr[left].dist < arr[smallest].dist) {
                smallest = left;
            }

            if (right < size &&
                arr[right].dist < arr[smallest].dist) {
                smallest = right;
            }

            if (smallest != index) {
                swapNodes(arr[index], arr[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }

    // Insert into heap
    void insert(int vertex, int dist) {

        if (size == capacity) {
            return;
        }

        arr[size] = HeapNode(vertex, dist);
        heapifyUp(size);
        size++;
    }

    // Extract minimum element
    HeapNode extractMin() {

        HeapNode root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return root;
    }

    bool isEmpty() {
        return size == 0;
    }

    ~MinHeap() {
        delete[] arr;
    }
};

// ================= GRAPH =================
class Graph {
public:
    int V;
    Node** adj;

    Graph(int vertices) {
        V = vertices;
        adj = new Node*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = nullptr;
        }
    }

    // Add directed edge
    void addEdge(int u, int v, int w) {
        Node* newNode = new Node(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    // Dijkstra using Min Heap
    void dijkstra(int source) {

        int* dist = new int[V];

        // Initialize distances
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
        }

        dist[source] = 0;
        MinHeap heap(V * V);
        heap.insert(source, 0);
        while (!heap.isEmpty()) {

            HeapNode minNode = heap.extractMin();

            int u = minNode.vertex;
            int currentDist = minNode.dist;

            // Ignore outdated entries
            if (currentDist > dist[u]) {
                continue;
            }

            // Traverse adjacency list
            Node* temp = adj[u];

            while (temp != nullptr) {

                int v = temp->vertex;
                int weight = temp->weight;

                // Relaxation
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    heap.insert(v, dist[v]);
                }

                temp = temp->next;
            }
        }

        // Print shortest distances
        cout << "Vertex\tDistance from Source\n";

        for (int i = 0; i < V; i++) {
            cout << i << "\t" << dist[i] << endl;
        }

        delete[] dist;
    }

    ~Graph() {

        for (int i = 0; i < V; i++) {
            Node* temp = adj[i];
            while (temp != nullptr) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }

        delete[] adj;
    }
};

// ================= MAIN =================
int main() {

    Graph g(5);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);

    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);

    g.addEdge(2, 3, 4);

    g.addEdge(3, 0, 7);
    g.addEdge(3, 2, 6);

    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 9);
    g.addEdge(4, 3, 2);

    g.dijkstra(0);

    return 0;
}