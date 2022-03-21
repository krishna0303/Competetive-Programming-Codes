// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    // Using DFS
    void topoSortUtil(int src,vector<int>adj[],vector<bool>&visited,stack<int>&ans){
	    visited[src]=true;
	    for(auto it:adj[src]){
	        if(!visited[it]){
	            topoSortUtil(it,adj,visited,ans);
	        }
	    }
	    ans.push(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>ans;
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            topoSortUtil(i,adj,visited,ans);
	        }
	    }
	   // topoSortUtil(0,adj,V,visited,ans);
	    vector<int>temp;
	    while(!ans.empty()){
	        temp.push_back(ans.top());
	       // cout<<t<<" ";
	        ans.pop();
	        
	    }
	    return temp;
	}
	//Function to return list containing vertices in Topological order using.

	// vector<int> topoSort(int V, vector<int> adj[]) 
	// {
	//     // code here
	//     vector<int>inorder(V,0);
	//     for(int i=0;i<V;i++){
	//         for(auto it:adj[i]){
	//             inorder[it]+=1;
	//         }
	//     }
	//     queue<int>q;
	//     for(int i=0;i<V;i++){
	//         if(inorder[i]==0){
	//             q.push(i);
	//         }
	//     }
	//     vector<int>ans;
	//     while(!q.empty()){
	//         int node=q.front();
	//         q.pop();
	//         ans.push_back(node);
	//         for(auto it:adj[node]){
	//             inorder[it]-=1;
	//             if(inorder[it]==0){
	//                 q.push(it);
	//             }
	//         }
	//     }
	//     return ans;
	// }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends