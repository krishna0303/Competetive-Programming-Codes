// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	void make_parent(vector<int>&parent){
	    for(int i=0;i<parent.size();i++){
	        parent[i]=i;
	    }
	}
	
	int findParent(vector<int>&parent,int x){
	    if(parent[x]!=x){
	        parent[x]=findParent(parent,parent[x]);
	    }
	    return parent[x];
	}
	
	void union_set(vector<int>&parent,vector<int>&rank,int x,int y){
	    int rootX=findParent(parent,x);
	    int rootY=findParent(parent,y);
	    if(rootX==rootY){
	        return;
	    }
	    if(rank[rootX]>rank[rootY]){
	        parent[rootY]=rootX;
	    }else{
	        parent[rootX]=rootY;
	        if(rank[rootX]==rank[rootY]){
	            rank[rootX]+=1;
	        }
	    }
	}
	
	bool compare( tuple<int,int,int>&a, tuple<int,int,int>&b){
	    return get<0>(a)<get<0>(b);
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int>parent(V);
       vector<int>rank(V,0);
       make_parent(parent);
       vector<tuple<int,int,int>>edges;
       for(int i=0;i<V;i++){
           for(auto it:adj[i]){
               edges.push_back(make_tuple(it[1],i,it[0]));
           }
       }
       sort(edges.begin(),edges.end());
       int result=0;
       for(int i=0;i<edges.size();i++){
           int x=get<1>(edges[i]);
           int y=get<2>(edges[i]);
           int weight=get<0>(edges[i]);
           if(findParent(parent,x)!=findParent(parent,y)){
               result+=weight;
               union_set(parent,rank,x,y);
           }
       }
       return result;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends