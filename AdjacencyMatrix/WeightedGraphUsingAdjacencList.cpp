#include <iostream>

// Node structure for the adjacency list
struct Node
{
    int vertex;
    int weight;
    Node *next;

    // Constructor
    Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
};

// Implementation of Weighted Graph using Adjacency List
class WeightedGraphList
{
private:
    int numVertices;
    Node **adjList;         // Array of pointers to node lists
    const int INF = 999999; // Representing infinity

public:
    // Constructor
    WeightedGraphList(int vertices)
    {
        numVertices = vertices;

        // Create an array of pointers to node lists
        adjList = new Node *[numVertices];

        // Initialize all head pointers to null
        for (int i = 0; i < numVertices; i++)
        {
            adjList[i] = nullptr;
        }
    }

    // Destructor to free allocated memory
    ~WeightedGraphList()
    {
        // Free memory for all nodes
        for (int i = 0; i < numVertices; i++)
        {
            Node *current = adjList[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }

        // Free memory for the array of pointers
        delete[] adjList;
    }

    // Add an edge with specified weight
    void addEdge(int src, int dest, int weight)
    {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
        {
            // Create a new node for the destination
            Node *newNode = new Node(dest, weight);

            // Add at the beginning of adjacency list for src
            newNode->next = adjList[src];
            adjList[src] = newNode;

            // For undirected graph, add edge from dest to src as well
            // Node* newNodeRev = new Node(src, weight);
            // newNodeRev->next = adjList[dest];
            // adjList[dest] = newNodeRev;
        }
        else
        {
            std::cout << "Invalid vertices!" << std::endl;
        }
    }

    // Remove an edge
    void removeEdge(int src, int dest)
    {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
        {
            // Handle case when the node to be deleted is the head
            if (adjList[src] != nullptr && adjList[src]->vertex == dest)
            {
                Node *temp = adjList[src];
                adjList[src] = adjList[src]->next;
                delete temp;
                return;
            }

            // Find the node to be deleted
            Node *current = adjList[src];
            Node *prev = nullptr;

            while (current != nullptr && current->vertex != dest)
            {
                prev = current;
                current = current->next;
            }

            // If node found, delete it
            if (current != nullptr)
            {
                prev->next = current->next;
                delete current;
            }

            // For undirected graph, remove the reverse edge too
            // Similar code for adjList[dest] would go here
        }
        else
        {
            std::cout << "Invalid vertices!" << std::endl;
        }
    }

    // Get weight of an edge
    int getWeight(int src, int dest)
    {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
        {
            Node *current = adjList[src];

            while (current != nullptr)
            {
                if (current->vertex == dest)
                {
                    return current->weight;
                }
                current = current->next;
            }
        }
        return INF; // Return INF if no edge exists
    }

    // Print the adjacency list
    void printGraph()
    {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < numVertices; i++)
        {
            std::cout << "Vertex " << i << ": ";

            Node *current = adjList[i];
            while (current != nullptr)
            {
                std::cout << "(" << current->vertex << ", " << current->weight << ") ";
                current = current->next;
            }

            std::cout << std::endl;
        }
    }
};

// Example usage
int main()
{
    int numVertices = 5;

    WeightedGraphList graph(numVertices);

    // Add edges
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 8);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 4, 1);
    graph.addEdge(3, 4, 4);

    // Print the graph
    graph.printGraph();

    return 0;
}