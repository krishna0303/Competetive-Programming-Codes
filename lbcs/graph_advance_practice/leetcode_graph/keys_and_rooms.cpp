#include<bits/stdc++.h>
using namespace std;
/*

There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

*/


class Solution {
public:
    void dfs(int src,vector<vector<int>>&rooms,vector<bool>&visited){
        visited[src]=true;
        for(auto it:rooms[src]){
            if(!visited[it]){
                dfs(it,rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count+=1;
                dfs(i,rooms,visited);
            }
        }
        if(count>1){
            return false;
        }else{
            return true;
        }
        
    }
};

