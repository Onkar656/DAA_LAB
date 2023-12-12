#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }
 
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }
    
    delete []first;
    delete []second;
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void mergeSort(int *arr, int s, int e) {

    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    for(int i=s;i<=mid;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr, s, mid);
    
    for(int i=mid+1;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr, mid+1, e);

    
    merge(arr, s, e);

}

int main() {

    int n;
    cout<<"Enter number of elements :"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand();
    }
cout<<"array before sorting :"<<endl;
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
     cout<<endl;
    mergeSort(arr, 0, n-1);
    cout<<"array after sorting :"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}

