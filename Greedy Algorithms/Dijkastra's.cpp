#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

const int V = 9; // Total number of vertices (0 to 8)

vector<pair<int, int>> graph[V]; // Adjacency list: graph[u] = {v, weight}

// Dijkstra's algorithm
void dijkstra(int src, int dest)
{
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        for (auto &[v, weight] : graph[u])
        {
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] == INT_MAX)
    {
        cout << "No path exists from " << src << " to " << dest << endl;
        return;
    }

    // Reconstruct the path
    stack<int> path;
    for (int at = dest; at != -1; at = parent[at])
        path.push(at);

    cout << "Shortest path from " << src << " to " << dest << ": ";
    while (!path.empty())
    {
        cout << path.top();
        path.pop();
        if (!path.empty())
            cout << " -> ";
    }

    cout << "\nTotal cost: " << dist[dest] << endl;
}

void buildGraph()
{
    // Edges from the image
    vector<tuple<int, int, int>> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}};

    for (auto &[u, v, w] : edges)
    {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Because it's an undirected graph
    }
}

int main()
{
    buildGraph();

    int from, to;
    cout << "Enter source node (0-8): ";
    cin >> from;
    cout << "Enter destination node (0-8): ";
    cin >> to;

    if (from < 0 || from >= V || to < 0 || to >= V)
    {
        cout << "Invalid node numbers!" << endl;
        return 1;
    }

    dijkstra(from, to);
    return 0;
}
