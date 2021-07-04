// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

 //for better understanding watch striver video

class Solution {
public:
/*

Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS). 
1. Assign RED color to the source vertex (putting into set U). 
2. Color all the neighbors with BLUE color (putting into set V). 
3. Color all neighbor’s neighbor with RED color (putting into set U). 
4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2. 
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite) 


*/
    //bipartite using BFS
    // bool isBipartiteUtil(vector<int>adj[],int V,int i,vector<int>visited){
    //     queue<int>q;
    //     int color=0;
    //     q.push(i);
    //     visited[i]=color;
    //     while(!q.empty()){
    //         int node=q.front();
            
    //         q.pop();
            
    //         for(auto it:adj[node]){
    //             if(visited[it]==-1){
                    
    //                 visited[it]=1-visited[node];
    //                 q.push(it);
    //             }
    //             else if(visited[it]==visited[node]){
    //                 return false;
    //             }

    //         }
            
    //     }
    //     return true;

    // }
	// bool isBipartite(int V, vector<int>adj[]){
	//     // Code here
	//     vector<int>visited(V,-1);
        
    //     for(int i=0;i<V;i++){
    //         if(visited[i]==-1){
    //             if(!isBipartiteUtil(adj,V,i,visited)){
    //                 return false;
    //             }
    //         }
    //     }
        
    //     return true;

	// }

    //Bipartite Using DFS
    bool isBipartiteUtil(vector<int>adj[],int V,int color,int i,vector<int>visited){
        
        
        visited[i]=color;
        
            
        for(auto it:adj[i]){
            if(visited[it]==-1){
                
                isBipartiteUtil(adj,V,1-visited[i],it,visited);
            }
            else if(visited[it]==visited[i]){
                return false;
            }

        }
            
       

    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>visited(V,-1);
        
        for(int i=0;i<V;i++){
            if(visited[i]==-1){
                if(!isBipartiteUtil(adj,V,0,i,visited)){
                    return false;
                }
            }
        }
        
        return true;

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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends