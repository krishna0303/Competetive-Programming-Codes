
#include<bits/stdc++.h>

using namespace std;
#define INF 9999999



 //for better understanding watch striver video

class Solution {
public:

   /*

   We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm. Following is detailed
    Kosaraju’s algorithm.
1) Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for
 adjacent vertices of a vertex, push the vertex to stack. In the above graph, if we start DFS from vertex 0,
 we get vertices in stack as 1, 2, 4, 3, 0.
2) Reverse directions of all arcs to obtain the transpose graph.
3) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. 
Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. 
In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).
   
   
   */

    
    

    void TopologicalSort_DFS(vector<int>adj[],int V,int i,vector<int>visited,stack<int>&s){
        visited[i]=1;
        for(auto it:adj[i]){
            if(!visited[it]){
                TopologicalSort_DFS(adj,V,it,visited,s);
            }
        }
        s.push(i);

    }

    void dfs(vector<int>transpose[],int V,int src,vector<int>visited){
        cout<<src<<" ";
        visited[src]=1;
        for(auto it:transpose[src]){
            if(!visited[it]){
                dfs(transpose,V,it,visited);
            }
        }
    }
	void KosarajuAlgo(int V, vector<int>adj[]){

        stack<int>s;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                TopologicalSort_DFS(adj,V,i,visited,s);
            }
        }
        vector<int>transpose[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                transpose[it].push_back(i);
            }
        }
        for(int i=0;i<V;i++){
            visited[i]=0;
        }
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(!visited[node]){
                dfs(transpose,V,node,visited);
                cout<<"\n";
            }
        }


    }



        

        
	    

	
    

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			
		}
        int src;
        cin>>src;
		Solution obj;
		 obj.KosarajuAlgo(V, adj);    
		
	}
	return 0;
}  // } Driver Code Ends