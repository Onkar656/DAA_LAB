#include<bits/stdc++.h>
using namespace std;
int linearserch(vector<int>& a,int n,int ele)
{
    int i;
    for( i=0;i<n;i++)
    {
        if(a[i]==ele)
        {
            cout<<"Eelment is found at ";
            return i;
        }
    }
        cout<<"Elememt not found";
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
     for(int i=0;i<n;i++)
     {
        cout<<a[i]<<" ";
     }
     
    int m;
    cout<<"\nEnter element to find "<<endl;
    cin>>m;
    cout<<linearserch(a,n,m)<<endl;
}