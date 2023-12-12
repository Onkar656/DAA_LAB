#include<bits/stdc++.h>
using namespace std;
int binaryserch(vector<int>& a,int n,int ele)
{
    int mid,first=1,last=n,i;
    mid=(first+last)/2;
    while(a[mid]!=ele&&first<=last)
    {
        if(a[mid]<ele)
            first=mid+1;
        else
            last=mid-1;
        mid=(first+last)/2;
       
    }
    if(a[mid]==ele)
    {
    cout<<"Element is found at ";
    return mid;}
    else
    cout<<"Element not found ";
    return 0;
}
int main()
{
     int n=100;
    srand(time(0));
    vector<int> a;
     while(a.size()<n){
        int m=(rand() % 1000 + 1);
        if(find(a.begin(),a.end(),m)!=a.end())
        continue;
        a.push_back(m); // Generates random numbers between 1 and 1000
     }
     sort(a.begin(),a.end());
     for(int i=0;i<n;i++)
     {
        cout<<a[i]<<" ";
     }
     
    int m;
    cout<<"\nEnter element to find "<<endl;
    cin>>m;
    cout<<binaryserch(a,n,m)<<endl;
    return 0;
}