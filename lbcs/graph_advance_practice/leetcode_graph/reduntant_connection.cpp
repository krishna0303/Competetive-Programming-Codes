#include<bits/stdc++.h>
using namespace std;

/*

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

 */

class Solution {
public:
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
    
    void set_union(vector<int>&parent,vector<int>&rank,int x,int y){
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
                rank[rootX]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        vector<int>parent(n+1);
        vector<int>rank(n+1,0);
        make_parent(parent);

        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int par1=findParent(parent,a);
            int par2=findParent(parent,b);
            if(par1==par2){
                ans.clear();
                ans.push_back(a);
                ans.push_back(b);
            }else{
                set_union(parent,rank,a,b);
            }
        }
        return ans;
        
    }
};