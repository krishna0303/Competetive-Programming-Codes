#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void findPath(int n,vector<vector<int>>& edges,int src,vector<bool>&visited,stack<int>&s,vector<vector<int>>&ans){
        
        if(src==(n-1)){
            s.push(src);
            vector<int>v;
            stack<int>temp;
            while(!s.empty()){
                int t=s.top();
                temp.push(t);
                s.pop();
            }
            while(!temp.empty()){
                int t=temp.top();
                temp.pop();
                v.push_back(t);
                s.push(t);
            }
            ans.push_back(v);
            s.pop();
            return;
            
        }
        visited[src]=true;
        s.push(src);
        
        for(auto it:edges[src]){
            // cout<<it<<endl;
            if(!visited[it]){
                findPath(n,edges,it,visited,s,ans);
            }
        }
        visited[src]=false;
        s.pop();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        vector<bool>visited(n,false);
        stack<int>s;
        findPath(n,graph,0,visited,s,ans);
        return ans;
        
    }
};