#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>&vis,vector<vector<int>>& image, int sr, int sc, int newColor,int n,int m,int oldColor){
        if(sr<0||sc<0||sr>=n||sc>=m||vis[sr][sc]==1||image[sr][sc]!=oldColor){
            return;
        }
        vis[sr][sc]=1;
        image[sr][sc]=newColor;
        dfs(vis,image,sr+1,sc,newColor,n,m,oldColor);
        dfs(vis,image,sr-1,sc,newColor,n,m,oldColor);
        dfs(vis,image,sr,sc+1,newColor,n,m,oldColor);
        dfs(vis,image,sr,sc-1,newColor,n,m,oldColor);
        
        
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // cout<<image.size()<<" "<<image[sr].size()<<endl;
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        dfs(vis,image,sr,sc,newColor,image.size(),image[0].size(),image[sr][sc]);
        return image;
        
    }
};