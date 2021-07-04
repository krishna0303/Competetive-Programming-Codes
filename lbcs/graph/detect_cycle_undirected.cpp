// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 /*
I have watched striver graph series for better understanding
 idea is to if any node is already visited  but it could be parent node of that node i.e 1->2 then 2->1 so we have to ignore it
 because and if node is already visited and if parent node is not equal to curerent node it means there is cycle

 make this graph
 5 5
0 4
1 2
1 4
2 3
3 4
and dry run for better understanding


 
 */



class Solution 
{
    public:
    // //Function to detect cycle in an undirected graph.

	//cycle detection in undirected graph using BFS
    // bool cycleBFS(vector<int>adj[],int i,vector<int>visited){
	//     queue<pair<int,int>>q;
	//     q.push({i,-1});
	//     visited[i]=1;
	//     while(!q.empty()){
	//         int node=q.front().first;
	//         int parent=q.front().second;
	//         q.pop();
	//         for(int j=0;j<adj[node].size();j++){
	//             if(!visited[adj[node][j]]){
	//                 q.push({adj[node][j],node});
	//                 visited[adj[node][j]]=1;
	//             }else if(visited[adj[node][j]]&&parent!=adj[node][j]){
	//                 return true;
	//             }
	//         }
	//     }
	//     return false;
	// }

	// bool isCycle(int V, vector<int>adj[])
	// {
	    
	//    	vector<int>visited(V,0);
	//    	for(int i=0;i<V;i++){
	//    	    if(!visited[i]){
	//    	        if(cycleBFS(adj,i,visited)){
	//    	            return true;
	//    	        }
	//    	    }
	   	    
	//    	}
	//    	return false;
	   
	// }

	//cycle detection in undirected graph using DFS
	bool cycleDFS(vector<int>adj[],int i,int parent,vector<int>visited){
	    
	    
	    visited[i]=1;
		for(auto it:adj[i]){
			if(!visited[it]){
				visited[i]=1;
				if(cycleDFS(adj,it,i,visited)){
					return true;
				}
			}else if(parent!=it){
				return true;

			}
		}
		return false;
	    
	        
	    
	}
	
	bool isCycle(int V, vector<int>adj[])
	{
	    
	   	vector<int>visited(V,0);
	   	for(int i=0;i<V;i++){
	   	    if(!visited[i]){
	   	        if(cycleDFS(adj,i,-1,visited)){
	   	            return true;
	   	        }
	   	    }
	   	    
	   	}
	   	return false;
	   
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends