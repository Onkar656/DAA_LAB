#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int numCities;
vector<vector<int>> costMatrix;
vector<bool> visited;
int currentCost = 0;
int bestCost = INF;
vector<int> bestTour;

void input() {
    cout << "Enter the number of cities: ";
    cin >> numCities;
    costMatrix.resize(numCities, vector<int>(numCities, 0));
    visited.resize(numCities, false);

    cout << "Enter the cost matrix (use " << INF << " for unconnected cities):" << endl;
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            cin >> costMatrix[i][j];
        }
    }
}

void branchAndBound(int currentCity) {
    if (currentCost >= bestCost)
        return;

    visited[currentCity] = true;
    bool allVisited = true;

    for (int i = 0; i < numCities; i++) {
        if (!visited[i]) {
            allVisited = false;
            currentCost += costMatrix[currentCity][i];
            branchAndBound(i);
            currentCost -= costMatrix[currentCity][i];
        }
    }

    visited[currentCity] = false;

    if (allVisited && costMatrix[currentCity][0] < bestCost) {
        bestCost = currentCost + costMatrix[currentCity][0];
        bestTour.clear();  // Clear the previous bestTour
        for (int i = 0; i < numCities; i++) {
            bestTour.push_back(i);  // Store the order of visited cities
        }
    }
}

int main() {
    input();
    branchAndBound(0);

    cout << "Best TSP Tour: ";
    for (int city : bestTour) {
        cout << city << " -> ";
    }
    cout << "0" << endl;

    cout << "Best Cost: " << bestCost << endl;

    return 0;
}
// 0 10 15 20 
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0