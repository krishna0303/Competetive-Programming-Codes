#include<bits/stdc++.h>
using namespace std;

void make_parent(vector<int>&parent){
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
    }
}

int find(vector<int>&parent,int x){
    if(x!=parent[x]){
        parent[x]=find(parent,parent[x]);  //path by compression optimization
    }
    return parent[x];
}
//union by rank optimization
void union_set(vector<int>&parent,vector<int>&rank,int x,int y){
    int rootX=find(parent,x);
    int rootY=find(parent,y);
    if(rootX==rootY){
        return;
    }
    if(rank[rootX]>rank[rootY]){
        parent[rootY]=rootX;
    }else{
        parent[rootX]=rootY;
        if(rank[rootX]==rank[rootY]){
            rank[rootY]++;
        }
    }
    
}


bool isCycle(vector<pair<int,int>>&allEdges,int n){
    vector<int>parent(n);
    vector<int>rank(n,0);
    make_parent(parent);
    for(int i=0;i<allEdges.size();i++){
        int rootX=find(parent,allEdges[i].first);
        int rootY=find(parent,allEdges[i].second);
        if(rootX==rootY){
            return true;
        }else{
            union_set(parent,rank,rootX,rootY);
        }
    }
    return false;

}
int main(){

    int n,e;
    cin>>n>>e;
    vector<int>edges[n];
    vector<pair<int,int>>allEdges(e);

    for(int j=0;j<e;j++){
            int u,v;
            cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);
            allEdges.push_back(make_pair(u,v));
            
    }

    bool ans=isCycle(allEdges,e);
    if(ans){
        cout<<"Cycle is present!\n";
    }else{
        cout<<"Cycle is not present ! \n";
    }


    return 0;
}