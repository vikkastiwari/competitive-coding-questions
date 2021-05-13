// Impelementing directed graph using adjacency list without STL
#include <bits/stdc++.h>
using namespace std;

// Structure of Node
struct Node
{
    int data;
    Node *next;
};

// Structure to store graph edges
struct Edge
{
    int src, dest;
};

class Graph
{
    int nodeCount;

    // creating new node in adjacency list
    Node *createAdjListNode(int dest, Node *head)
    {
        Node *newNode = new Node;
        newNode->data = dest;
        newNode->next = head;
        return newNode;
    }

public:
    // An array of pointers to Node to represent adjacency list
    Node **head;
    Graph(Edge edges[], int sizeOfEdges, int nodeCount)
    {
        // allocate memory
        head = new Node *[nodeCount]();
        this->nodeCount = nodeCount;

        // Initialize head pointer for all vertices
        for (int i = 0; i < nodeCount; i++)
        {
            head[i] = NULL;
        }

        for (int i = 0; i < sizeOfEdges; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            // Inserting new node at the beginning
            Node *newNode = createAdjListNode(dest, head[src]);
            // point head pointer to the new node
            head[src] = newNode;
        }
    }
};

// print all neighboring vertices of given vertex
void printList(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << " -> " << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    // array of graph edges as per above diagram.
    Edge edges[] = {
        // pair (src, dest) represents edge from src to dest
        {0, 1},
        {1, 2},
        {2, 0},
        {2, 1},
        {3, 2},
        {4, 5},
        {5, 4}};

    int nodeCount = 6;
    int sizeOfEdges = sizeof(edges) / sizeof(edges[0]);

    Graph graph(edges, sizeOfEdges, nodeCount);
    for (int i = 0; i < nodeCount; i++)
    {
        cout << i << " --";
        printList(graph.head[i]);
    }

    return 0;
}