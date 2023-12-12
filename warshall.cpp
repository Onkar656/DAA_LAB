#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INF = 99999; // Represents infinity for unreachable vertices

void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();

    // Applying the algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }

        // Print the current state of the graph after each iteration
        cout << "Intermediate graph after iteration " << k + 1 << ":" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] == INF)
                    cout << "INF\t";
                else
                    cout << graph[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    // Creating a matrix to store the graph (adjacency matrix)
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix of the graph (Enter INF for infinity):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            string input;
            cin >> input;
            if (input == "INF") {
                graph[i][j] = INF;
            } else {
                graph[i][j] = stoi(input);
            }
        }
    }

    floydWarshall(graph);

    // Printing the shortest paths between all pairs of vertices
    cout << "Shortest paths between all pairs of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                cout << "INF\t";
            else
                cout << graph[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
/*
0 4 INF 5 INF
INF 0 1 INF 6
2 INF 0 3 INF
INF INF 1 0 2
1 INF INF 4 0
*/