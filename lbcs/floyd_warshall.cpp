#include<bits/stdc++.h>
using namespace std;
#define INF 999999


/*
We initialize the solution matrix same as the input graph matrix as a first step. 
Then we update the solution matrix by considering all vertices as an intermediate vertex. 
The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an
 intermediate vertex in the shortest path. When we pick vertex number k as an intermediate vertex, 
 we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. For every pair (i, j) of the source 
 and destination vertices respectively, there are two possible cases. 
1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is. 
2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
The following figure shows the above optimal substructure property in the all-pairs shortest path problem.

*/
void printdfs(int**edges,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void floydwarshall(int **edges,int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                edges[i][j]=min(edges[i][j],edges[i][k]+edges[k][j]);

            }
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
        int u,v,w;
        cin>>u>>v>>w;
        edges[u][v]=w;
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(edges[i][j]==0){
                edges[i][j]=INF;
            }
        }
    }
    // printbfs(edges,n);
    cout<<"Original Matrix :\n";
    printdfs(edges,n);
    floydwarshall(edges,n);
    cout<<"After Apply floyd-warshal algorithm Matrix :\n";
    printdfs(edges,n);

    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;


    return 0;

}