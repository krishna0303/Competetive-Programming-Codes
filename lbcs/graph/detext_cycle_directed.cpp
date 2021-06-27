// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	
	bool solve(int sv,vector<int> adj[],vector<bool>&visited,vector<bool>&order){
	    order[sv]=true;
	    visited[sv]=true;
	    for(int i=0;i<adj[sv].size();i++){
	        if(!visited[adj[sv][i]]){
	            bool con=solve(adj[sv][i],adj,visited,order);
	            if(con==true){
	                return true;
	            }
	            
	        }else{
	            if(order[adj[sv][i]]==true){
	                return true;
	            }
	        }
	    }
	    order[sv]=false;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool>visited(V,false);
	   	vector<bool>order(V,false);
	   	for(int i=0;i<V;i++){
	   	    if(!visited[i]){
	   	        bool cycle=solve(i,adj,visited,order);
	   	        if(cycle==true){
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends