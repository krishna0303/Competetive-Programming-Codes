// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//USING DFS


	//Function to detect cycle in a directed graph using DFS
	// for better understanding watch striver video

	//here visited array handle is node is one time visisted or not and oder array is handling is there any node who are already visited in a single move or in a path
	//TC-O(n+E)
	//SC-O(2n)
	// auxilary space complexity-O(n)  it is used for recursion call

	// bool solve(int sv,vector<int> adj[],vector<bool>&visited,vector<bool>&order){
	//     order[sv]=true;
	//     visited[sv]=true;
	//     for(int i=0;i<adj[sv].size();i++){
	//         if(!visited[adj[sv][i]]){
	//             bool con=solve(adj[sv][i],adj,visited,order);
	//             if(con==true){
	//                 return true;
	//             }
	            
	//         }else{
	//             if(order[adj[sv][i]]==true){
	//                 return true;
	//             }
	//         }
	//     }
	//     order[sv]=false;
	//     return false;
	// }
	// bool isCyclic(int V, vector<int> adj[]) 
	// {
	//    	// code here
	//    	vector<bool>visited(V,false);
	//    	vector<bool>order(V,false);
	//    	for(int i=0;i<V;i++){
	//    	    if(!visited[i]){
	//    	        bool cycle=solve(i,adj,visited,order);
	//    	        if(cycle==true){
	//    	            return true;
	//    	        }
	//    	    }
	//    	}
	//    	return false;
	// }


	/*
	USING BFS(KAHN'S ALGORITHM)

    algorithms is almost similar only there is slight change
	//if we are not able to generate topological sort it means there exist cycle
	 because for topological sort graph must be directed ACYCLIC graph (DAG)
	 TC-O(V+E)
	 SC-O(V)


	*/

    bool kahns_algo(vector<int>adj[],int V){
		queue<int>q;
		vector<int>indegree(V,0);
		for(int i=0;i<V;i++){
			for(auto it:adj[i]){
				indegree[it]+=1;
			}
		}
		for(int i=0;i<V;i++){
			if(indegree[i]==0){
				q.push(i);
			}
		}
		int cnt=0;
		while(!q.empty()){
			int node=q.front();
			q.pop();
			cnt++;
			for(auto it:adj[node]){
				
				indegree[it]-=1;
				if(indegree[it]==0){
					q.push(it);
				}
			}
		}
		if(cnt==V){  //if cnt==V it means there is possible to generate a topological sort because it has considered all nodes or visit all nodes during kahn's algo due to this cnt has become equal to V i.e no  of vertices
			return false;
		}
		return true;
	}
    bool isCyclic(int V, vector<int> adj[]) 
	{
	   	
	   	if(kahns_algo(adj,V)){
			   return true;
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