#include <iostream>

// Implementation of Weighted Graph using Adjacency Matrix
class WeightedGraphMatrix
{
private:
    int numVertices;
    int **adjMatrix;
    const int INF = 999999; // Representing infinity

public:
    // Constructor
    WeightedGraphMatrix(int vertices)
    {
        numVertices = vertices;

        // Allocate memory for the adjacency matrix
        adjMatrix = new int *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new int[numVertices];
        }

        // Initialize matrix with INF (representing no edge)
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                if (i == j)
                    adjMatrix[i][j] = 0; // Distance to self is 0
                else
                    adjMatrix[i][j] = INF;
            }
        }
    }

    // Destructor to free allocated memory
    ~WeightedGraphMatrix()
    {
        for (int i = 0; i < numVertices; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    // Add an edge with specified weight
    void addEdge(int src, int dest, int weight)
    {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
        {
            adjMatrix[src][dest] = weight;
            // For undirected graph, uncomment the line below
            // adjMatrix[dest][src] = weight;
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
            adjMatrix[src][dest] = INF;
            // For undirected graph, uncomment the line below
            // adjMatrix[dest][src] = INF;
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
            return adjMatrix[src][dest];
        }
        return INF;
    }

    // Print the adjacency matrix
    void printGraph()
    {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                if (adjMatrix[i][j] == INF)
                {
                    std::cout << "INF\t";
                }
                else
                {
                    std::cout << adjMatrix[i][j] << "\t";
                }
            }
            std::cout << std::endl;
        }
    }
};

// Example usage
int main()
{
    int numVertices = 5;

    WeightedGraphMatrix graph(numVertices);

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