
#include<bits/stdc++.h>

using namespace std;
#define INF 9999999



 //for better understanding watch striver video

class Solution {
public:

   /*

   TC-O(V+E)
   SC-O(V)+O(V)
   
   */

    void shortestPathUtil(vector<int>adj[],int V,vector<int>&distance,int src){
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if((distance[node]+1)<distance[it]){
                    distance[it]=distance[node]+1;
                    q.push(it);
                }
                
            }
        }
        
        
            
       

    }
	void shortestPath(int V, vector<int>adj[],int src){
        vector<int>distance(V,INF);
        distance[src]=0;
        shortestPathUtil(adj,V,distance,src);
        for(int i=0;i<V;i++){
            cout<<distance[i]<<" ";
        }
        cout<<endl;

	    
	    

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
        int src;
        cin>>src;
		Solution obj;
		 obj.shortestPath(V, adj,src);    
		
	}
	return 0;
}  // } Driver Code Ends