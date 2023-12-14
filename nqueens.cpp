#include <iostream>
#include <vector>
using namespace std;

int board[20][20];
int solutionCount = 0;

bool isSafe(int row, int col, int N) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int N, int col) {
    if (col == N) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Queens' coordinates:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    cout << "(" << i+1 << ", " << j+1 << ") ";
                }
            }
        }
        cout << "\n\n";
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, N)) {
            board[i][col] = 1;
            res = solveNQueensUtil(N, col + 1) || res;
            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

void solveNQueens(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQueensUtil(N, 0)) {
        cout << "Solution does not exist" << endl;
    }
}

int main() {
    int N;

    cout << "Enter the board size (N): ";
    cin >> N;

    solveNQueens(N);
    cout << "Total number of solutions: " << solutionCount << endl;

    return 0;
}