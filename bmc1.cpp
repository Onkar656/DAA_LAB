#include<bits/stdc++.h>
using namespace std;


void processArray(vector<int> &ans){

    for(int i=0)
}

int main(){
    vector<int> ans;
    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        ans.push_back(x);
    }
    int count=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i]%6==0){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}