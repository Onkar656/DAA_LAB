#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<int>& path) {
    cout << "Hamiltonian Cycle: ";
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << path[0] << endl;
}

bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

void hamiltonianCyclesUtil(const vector<vector<int>>& graph, vector<int>& path, int pos, int& count, vector<vector<int>>& allCycles) {
    int V = graph.size();
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            count++;
            allCycles.push_back(path);
        }
        return;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            hamiltonianCyclesUtil(graph, path, pos + 1, count, allCycles);
            path[pos] = -1;
        }
    }
}

int countAndPrintHamiltonianCycles(const vector<vector<int>>& graph, vector<vector<int>>& allCycles) {
    int count = 0;
    int V = graph.size();
    vector<int> path(V, -1);
    path[0] = 0;
    hamiltonianCyclesUtil(graph, path, 1, count, allCycles);
    return count;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> allCycles;
    int totalSolutions = countAndPrintHamiltonianCycles(graph, allCycles);

    if (totalSolutions > 0) {
        cout << "Total number of Hamiltonian Cycles: " << totalSolutions << endl;
        cout << "All Hamiltonian Cycles:" << endl;
        for (const auto& cycle : allCycles) {
            printSolution(cycle);
        }
    } else {
        cout << "No Hamiltonian Cycles found." << endl;
    }

    return 0;
}