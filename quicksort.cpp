#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    cout << "Pivot: " << pivot << endl;

    int cnt = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    cout << "Partitioned Array: ";
    printArray(arr, e + 1);

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    cout << "After Partitioning: ";
    printArray(arr, e + 1);

    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    srand(time(0)); 

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Initial Array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}

