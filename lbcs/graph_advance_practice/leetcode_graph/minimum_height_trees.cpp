#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>v;
        if(n<=0){
            return v;
        }
        if(n==1){
            v.push_back(0);
            return v;
        }
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]+=1;
            indegree[edges[i][1]]+=1;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        vector<bool>visited(n,false);
        
        int count=n;
        while(count>2){
            int siz=q.size();
            count-=siz;
            for(int i=0;i<siz;i++){
                int node=q.front();
                q.pop();
                visited[node]=true;
                for(auto it:adj[node]){
                if(!visited[it]){
                   
                    indegree[it]-=1;
                    
                    if(indegree[it]==1){
                        q.push(it);
                    }
                    
                }
                
                
            }
            }
            
            
            
        }
        
        while(!q.empty()){
            v.push_back(q.front());
                q.pop();
            
        }
        return v;
        
        
        
        
        
    }
};