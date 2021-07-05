#include<bits/stdc++.h>
using namespace std;

/*
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
    /*
    TC-O(V+E)
    SC-O(N)
    ASC-O(N)
    
    */
// 	void TopologicalSortDFS(vector<int>adj[],int V,int i,vector<int>&visited,stack<int>&s){
// 	    visited[i]=1;
// 	    for(auto it:adj[i]){
// 	        if(!visited[it]){
// 	            TopologicalSortDFS(adj,V,it,visited,s);
// 	        }
// 	    }
// 	    s.push(i);
	    
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
	    
// 	    stack<int>s;
// 	    vector<int>visited(V,0);
// 	    for(int i=0;i<V;i++){
// 	        if(!visited[i]){
// 	            TopologicalSortDFS(adj,V,i,visited,s);
// 	        }
// 	    }
// 	    vector<int>v;
// 	    while(!s.empty()){
// 	        int t=s.top();
// 	        s.pop();
// 	        v.push_back(t);
	        
// 	    }
// 	    return v;
// 	}
// };

// // { Driver Code Starts.

// /*  Function to check if elements returned by user
// *   contains the elements in topological sorted form
// *   V: number of vertices
// *   *res: array containing elements in topological sorted form
// *   adj[]: graph input
// */
// int check(int V, vector <int> &res, vector<int> adj[]) {
//     vector<int> map(V, -1);
//     for (int i = 0; i < V; i++) {
//         map[res[i]] = i;
//     }
//     for (int i = 0; i < V; i++) {
//         for (int v : adj[i]) {
//             if (map[i] > map[v]) return 0;
//         }
//     }
//     return 1;
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         int N, E;
//         cin >> E >> N;
//         int u, v;

//         vector<int> adj[N];

//         for (int i = 0; i < E; i++) {
//             cin >> u >> v;
//             adj[u].push_back(v);
//         }
        
//         Solution obj;
//         vector <int> res = obj.topoSort(N, adj);

//         cout << check(N, res, adj) << endl;
//     }
    
//     return 0;
// }  // } Driver Code Ends








/*

Applications: 
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs.
 In computer science, applications of this type arise in instruction scheduling, ordering of formula cell 
 evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation 
 tasks to perform in make files,
 data serialization, and resolving symbol dependencies in linkers
*/


/*
Kahn' algorithm
Algorithm: Steps involved in finding the topological ordering of a DAG:
Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.

Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
Step 5: Repeat Step 3 until the queue is empty.

TC-O(V+E)
SC-O(V)+O(V)

striver video

*/


vector<int> Kahns_Algo(int **edges,int n){
    queue<int>q;
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]){
                indegree[j]+=1;
            }
        }
    }

    vector<int>ans;
    
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int val=q.front();
        q.pop();
        ans.push_back(val);
        for(int i=0;i<n;i++){
            if(i==val){
                continue;
            }
            if(edges[val][i]){
                indegree[i]-= 1;
                if(indegree[i]==0){
                    q.push(i);
                }


            }
        }
    }

    return ans;

    



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
    for(int j=0;j<e;j++){
            int u,v;
            cin>>u>>v;
            edges[u][v]=1;//because directed graph
            
    }
    vector<int>ans=Kahns_Algo(edges,n);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    


    return 0;
}