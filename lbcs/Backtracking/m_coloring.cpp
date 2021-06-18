// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(int node,bool graph[101][101], int V,int color[],int col){
    for(int i=0;i<V;i++){   //for all adjacent nodes of current node
        if(graph[node][i]){ //ifthis condition true it means there is an edge between current node and ith node it means ith node is adjacent of current node
            if(color[i]==col){  //so checking if it ith node is already coloured with the same color then retuen false we 
                return false;   //can't give the same color  to this current node 
            }
            
        }
    }
    return true;  //if this color is not holding any adjacent nodes of current nodes then return true;
    
}
bool solve(int node,bool graph[101][101], int m, int V,int color[]){
    if(node==V){  // if node reach the total nodes value then it means that it is possible to give the color to all nodes so return true
        return true;
    }
    for(int i=1;i<=m;i++){    //checking each color one by one
        if(isSafe(node,graph,V,color,i)){ //this will check if neighbours of current node has already this current ith color or not if not then it is safe to use the ith color for this current node
            color[node]=i;      //give this ith color to current node and marke it in color[].
            if(solve(node+1,graph,m,V,color)){ //call for next nodes if it will also return the true then return true else remove this color from the current node and check for another color because considering this color it is not possible to fill colors to future nodes
                return true;
            }
            color[node]=0;
            
            
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V];  //it is used to handle the color nodes
    if(solve(0,graph,m,V,color)){
        return true;
    }else{
        return false;
    }
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends