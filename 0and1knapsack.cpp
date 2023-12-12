#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsackDP(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxProfit = dp[n][W];
    cout << "Maximum Profit: " << maxProfit << endl;

    vector<int> selectedItems(n, 0);

    int remainingWeight = W;
    for (int i = n; i > 0 && maxProfit > 0; i--) {
        if (maxProfit != dp[i - 1][remainingWeight]) {
            selectedItems[i - 1] = 1;
            maxProfit -= val[i - 1];
            remainingWeight -= wt[i - 1];
        }
    }

    cout << "Chosen Items: <";
    for (int i = 0; i < n; i++) {
        cout << selectedItems[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
    cout << ">" << endl;
}

int main() {
    int n;
    cout << "Number of items: ";
    cin >> n;

    int W;
    cout << "Enter the maximum weight (Knapsack capacity): ";
    cin >> W;

    int profit[n];
    int weight[n];

    cout << "Enter Weight Array: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter Profit Array: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    knapsackDP(W, weight, profit, n);

    return 0;
}