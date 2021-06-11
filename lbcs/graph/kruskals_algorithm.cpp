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

bool compare(const tuple<int,int,int>&a,const tuple<int,int,int>&b){
    int first=get<2>(a);
    int second=get<2>(b);
    if(first<second){
        return true;
    }
    return false;

}

vector<tuple<int,int,int>> kruskalsAlgo(vector<tuple<int,int,int>>&allEdges,int n){
    vector<tuple<int,int,int>>result;
    vector<int>parent(n);
    vector<int>rank(n,0);
    make_parent(parent);

    sort(allEdges.begin(),allEdges.end(),compare);
    for(int i=0;i<allEdges.size();i++){
        int rootX=find(parent,get<0>(allEdges[i]));
        int rootY=find(parent,get<1>(allEdges[i]));
        if(rootX!=rootY){
            result.push_back(allEdges[i]);
            union_set(parent,rank,rootX,rootY);
        }
    }
    return result;

}
int main(){

    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>>edges(n,vector<pair<int,int>>(n));
    vector<tuple<int,int,int>>allEdges(e);

    for(int j=0;j<e;j++){
            int u,v,w;
            cin>>u>>v>>w;
            edges[u].push_back(make_pair(v,w));
            edges[v].push_back(make_pair(u,w));
            allEdges.push_back(make_tuple(u,v,w));
            
    }

    vector<tuple<int,int,int>>res=kruskalsAlgo(allEdges,n);
    for(int i=0;i<res.size();i++){
        cout<<get<0>(res[i])<<" "<<get<1>(res[i])<<" "<<get<2>(res[i])<<"\n";
    }


    return 0;
}