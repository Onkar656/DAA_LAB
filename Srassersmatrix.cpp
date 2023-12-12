#include <iostream>
#include <vector>

using namespace std;

// Function to display a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to perform Strassen's matrix multiplication
vector<vector<int>> strassenMatrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: If the matrix size is 1x1, just multiply the elements
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Calculate half size
    int halfSize = n / 2;

    // Split matrices A and B into four smaller matrices
    vector<vector<int>> A11(halfSize, vector<int>(halfSize));
    vector<vector<int>> A12(halfSize, vector<int>(halfSize));
    vector<vector<int>> A21(halfSize, vector<int>(halfSize));
    vector<vector<int>> A22(halfSize, vector<int>(halfSize));

    vector<vector<int>> B11(halfSize, vector<int>(halfSize));
    vector<vector<int>> B12(halfSize, vector<int>(halfSize));
    vector<vector<int>> B21(halfSize, vector<int>(halfSize));
    vector<vector<int>> B22(halfSize, vector<int>(halfSize));

    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }

    // Calculate intermediate matrices
    vector<vector<int>> S1(halfSize, vector<int>(halfSize));
    vector<vector<int>> S2(halfSize, vector<int>(halfSize));
    vector<vector<int>> S3(halfSize, vector<int>(halfSize));
    vector<vector<int>> S4(halfSize, vector<int>(halfSize));
    vector<vector<int>> S5(halfSize, vector<int>(halfSize));
    vector<vector<int>> S6(halfSize, vector<int>(halfSize));
    vector<vector<int>> S7(halfSize, vector<int>(halfSize));

    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            S1[i][j] = B12[i][j] - B22[i][j];
            S2[i][j] = A11[i][j] + A12[i][j];
            S3[i][j] = A21[i][j] + A22[i][j];
            S4[i][j] = B21[i][j] - B11[i][j];
            S5[i][j] = A11[i][j] + A22[i][j];
            S6[i][j] = B11[i][j] + B22[i][j];
            S7[i][j] = A12[i][j] - A22[i][j];
        }
    }

    // Recursively compute seven products
    vector<vector<int>> P1 = strassenMatrixMultiply(A11, S1);
    vector<vector<int>> P2 = strassenMatrixMultiply(S2, B22);
    vector<vector<int>> P3 = strassenMatrixMultiply(S3, B11);
    vector<vector<int>> P4 = strassenMatrixMultiply(A22, S4);
    vector<vector<int>> P5 = strassenMatrixMultiply(S5, S6);
    vector<vector<int>> P6 = strassenMatrixMultiply(S7, B21);
    vector<vector<int>> P7 = strassenMatrixMultiply(A21, S6);

    // Calculate result matrices
    vector<vector<int>> C11(halfSize, vector<int>(halfSize));
    vector<vector<int>> C12(halfSize, vector<int>(halfSize));
    vector<vector<int>> C21(halfSize, vector<int>(halfSize));
    vector<vector<int>> C22(halfSize, vector<int>(halfSize));

    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            C11[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C12[i][j] = P1[i][j] + P2[i][j];
            C21[i][j] = P3[i][j] + P4[i][j];
            C22[i][j] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }

    // Combine the result matrices into a single matrix
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + halfSize] = C12[i][j];
            C[i + halfSize][j] = C21[i][j];
            C[i + halfSize][j + halfSize] = C22[i][j];
        }
    }

    // Print intermediate results
    cout << "Intermediate Result (S1):" << endl;
    printMatrix(S1);
    cout << "Intermediate Result (S2):" << endl;
    printMatrix(S2);
    cout << "Intermediate Result (S3):" << endl;
    printMatrix(S3);
    cout << "Intermediate Result (S4):" << endl;
    printMatrix(S4);
    cout << "Intermediate Result (S5):" << endl;
    printMatrix(S5);
    cout << "Intermediate Result (S6):" << endl;
    printMatrix(S6);
    cout << "Intermediate Result (S7):" << endl;
    printMatrix(S7);

    cout << "Intermediate Result (C11):" << endl;
    printMatrix(C11);
    cout << "Intermediate Result (C12):" << endl;
    printMatrix(C12);
    cout << "Intermediate Result (C21):" << endl;
    printMatrix(C21);
    cout << "Intermediate Result (C22):" << endl;
    printMatrix(C22);

    return C;
}

int main() {
    int n;
    cout << "Enter the size of the matrices: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    cout << "Enter matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    cout << "Intermediate Results:" << endl;
    vector<vector<int>> result = strassenMatrixMultiply(A, B);

    cout << "Final Result (A * B using Strassen's method):" << endl;
    printMatrix(result);

    return 0;
}