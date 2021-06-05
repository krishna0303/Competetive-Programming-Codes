#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,e;
    cin>>n>>e;
    vector<int>edges[n];
    
    //this is for not weighted graph for weighted graph instead of 1 put weight of edge
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<edges[i].size();j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }
     

    return 0;

}