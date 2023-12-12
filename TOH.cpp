#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 void TowerOfHonoi(int n, char from_rod, char to_rod, char aux_rod,int &count){

    if (n == 0) {
        return;
    }
     count++;
    TowerOfHonoi(n - 1, from_rod, aux_rod, to_rod,count);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    TowerOfHonoi(n - 1, aux_rod, to_rod, from_rod,count);
}
int main(){
    int n;
    cout<<"enter the number of disk"<<endl;
    cin>>n;
    int count=0;
    TowerOfHonoi(n,'A','C','B',count);
    cout<<"The number of steps required are->> "<<count<<endl;
    return 0;
}