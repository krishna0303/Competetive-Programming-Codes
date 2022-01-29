#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1){
            return true;
        }
        vector<bool>visited(n,false);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            int node=q.front();
            visited[node]=true;
            q.pop();
            for(auto it:adj[node]){
                if(!visited[it]){
                    if(it==destination){
                        return true;
                    }
                    q.push(it);
                }
            }
        }
        return false;
        
        
    }
};