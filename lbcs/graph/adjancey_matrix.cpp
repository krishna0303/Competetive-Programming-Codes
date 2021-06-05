#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    //this is for not weighted graph for weighted graph instead of 1 put weight of edge
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        edges[u][v]=1;
        edges[v][u]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }
     

    return 0;

}