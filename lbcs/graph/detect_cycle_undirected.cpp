// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool solve(int sv,vector<int>adj[],int parent,vector<bool>&visited){
        visited[sv]=true;
        for(auto x:adj[sv]){
            if(!visited[x]){
                
                bool conf=solve(x,adj,sv,visited);
                if(conf){
                    return true;
                }
            }
            else if(parent!=x){
                return true;
            }
        }
        visited[sv]=false;
        
        return false;
        
        
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            bool flag=solve(i,adj,-1,visited);
	            if(flag){
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