#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>  // Added for path reconstruction

using namespace std;

#define INF INT_MAX

// Structure to represent a vertex in the graph
struct Vertex {
    int id;
    int distance;
};

// Comparison function for priority queue
struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance;
    }
};

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<pair<int, int>>>& graph, int source, int destination) {
    int V = graph.size();

    // Priority queue to store vertices and their distances
    priority_queue<Vertex, vector<Vertex>, CompareVertex> pq;

    // Initialize distances to all vertices as INF
    vector<int> distance(V, INF);

    // Set the distance of the source vertex to itself as 0
    distance[source] = 0;

    // Enqueue the source vertex
    pq.push({source, 0});

    // Vector to store the parent of each vertex
    vector<int> parent(V, -1);

    while (!pq.empty()) {
        // Extract the vertex with the minimum distance
        Vertex current = pq.top();
        pq.pop();

        int u = current.id;

        // Iterate through all adjacent vertices of the current vertex
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({v, distance[v]});
                parent[v] = u; // Update the parent of v
            }
        }
    }

    // Display distances from the source vertex to all other vertices
    cout << "Distances from source vertex " << source << " to all other vertices:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == INF) {
            cout << "INF";
        } else {
            cout << distance[i];
        }
        cout << endl;
    }

    // Print the path from source to destination
    if (parent[destination] == -1) {
        cout << "No path from source to destination." << endl;
    } else {
        cout << "Shortest path from source to destination:" << endl;
        stack<int> path;
        int current = destination;
        while (current != -1) {
            path.push(current);
            current = parent[current];
        }
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Shortest distance from source to destination: " << distance[destination] << endl;
    }
}

int main() {
    int V, E; // V: number of vertices, E: number of edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    int destination; // Add destination input
    cout << "Enter the destination vertex: ";
    cin >> destination;

    // Perform Dijkstra's algorithm and print the path
    dijkstra(graph, source, destination);

    return 0;
}


/*
example vertex with their edges
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
8 6 6
6 5 2
3 5 14
3 4 9
5 4 10
7 8 7
7 6 1
*/