#include<bits/stdc++.h>
using namespace std;


/*
4 methods to represents fraph
1->adjancey matrxi
2->adjancey list
3->incidence matrix
4->incidence list

*/

//BFS and DFS for connected graph

void bfs(int **edges,int n,int sv,bool *visited){
    queue<int>q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int ans=q.front();
        q.pop();
        cout<<ans<<" ";
        for(int i=0;i<n;i++){
            if(i==ans){
                continue;
            }
            if(edges[ans][i]&&!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

void dfs(int**edges,int n,int sv,bool* visited){
    cout<<sv<<" ";
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]&&!visited[i]){
            dfs(edges,n,i,visited);
        }
    }
}

void dfs_iterative(int**edges,int n,int sv,bool *visisted){
    stack<int>s;
    s.push(sv);
    visisted[sv]=true;
    while(!s.empty()){
        int ans=s.top();
        s.pop();
        cout<<ans<<" ";
        for(int i=0;i<n;i++){
            if(i==ans){
                continue;
            }
            if(edges[ans][i]&&!visisted){
                s.push(i);
                visisted[i]=true;
            }
        }
    }
}


//BFS and DFS for disconnected graph

void printbfs(int **edges,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(edges,n,i,visited);
        }
    }
    
}

void printdfs(int **edges,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs_iterative(edges,n,i,visited);
        }
    }
    
}

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
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        edges[u][v]=1;
        edges[v][u]=1;
    }
    // printbfs(edges,n);
    printdfs(edges,n);

    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;


    return 0;
}