
#include<bits/stdc++.h>

using namespace std;
#define INF 9999999



 //for better understanding watch striver video

class Solution {
public:

   /*
   For all who are wondering the intution behind Topological sorting and why haven't we use simple DFS or BFS from the source node instead .
READ THIS.................

lets say you want to do it using DFS
yes you can do it using DFS , but consider the case when you already updated a node's distance by a dfs() call and lets say
 its 7 and as it is DFS then its obvious that you also have updated all the nodes in its segment of DFS call .
  now you have reached to the same node from different dfs() call and now the distance is 4 , so in order to update all
   the nodes which were affected by the DFS call previously on the node considering distance as 7 , you now again have to 
   do the same so that its updated with new min distance.
Same is the scenario for the simple BFS approach.
This multiple time calling DFS/BFS degrades the Time Complexity, hence Topological Ordering save you from
 that overhead as you already know which nodes will come after the current node , so you keep on updating it .

 this problem is same in shorstest path in undirected graph but we can't apply topological sortr in indirected graph but in DAG we
 have opportunity to use topological sort to save time

 as we know in topological sorting nodes are sorted on their dependency on another nodes so first node is not dependent any node 
 so but on this node there are lots of nodes are present in the forward direction so update on this node will affect all nodes whcih are adjacent to this node
 so after topological sort finding shortest path is saving much time of repeateadly updation of all nodes

   TC-O(V+E)*2
   SC-O(2V)
   
   */

    
    

    void TopologicalSort_DFS(vector<pair<int,int>>adj[],int V,int i,vector<int>visited,stack<int>&s){
        visited[i]=1;
        for(auto it:adj[i]){
            if(!visited[it.first]){
                TopologicalSort_DFS(adj,V,it.first,visited,s);
            }
        }
        s.push(i);

    }
	void shortestPath(int V, vector<pair<int,int>>adj[],int src){

        stack<int>s;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                TopologicalSort_DFS(adj,V,i,visited,s);
            }
        }

        vector<int>distance(V,INF);
        distance[src]=0;

        while(!s.empty()){
            int node=s.top();
            s.pop();
            for(auto it:adj[node]){
                if(distance[node]!=INF){
                     if((distance[node]+it.second)<distance[it.first]){
                    distance[it.first]=distance[node]+it.second;
                }

                }
               
            }

        }
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
		vector<pair<int,int>>adj[V];
		for(int i = 0; i < E; i++){
			int u, v,w;
			cin >> u >> v>>w;
			adj[u].push_back({v,w});
			
		}
        int src;
        cin>>src;
		Solution obj;
		 obj.shortestPath(V, adj,src);    
		
	}
	return 0;
}  // } Driver Code Ends