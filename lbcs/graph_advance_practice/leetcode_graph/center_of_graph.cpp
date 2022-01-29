
#include<bits/stdc++.h>
using namespace std;
/*

There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

*/
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // int node1=edges[0][0];
        // int node2=edges[0][1];
        
        if(edges[1][0]==edges[0][0]||edges[1][1]==edges[0][0]){
            return edges[0][0];
        }else{
            return edges[0][1];
        }
        
//         map<int,int>m;
//         for(int i=0;i<edges.size();i++){
//             m[edges[i][0]]+=1;
//             m[edges[i][1]]+=1;
//         }
//         int maxm=INT_MIN;
//         int node=0;
//         for(auto it:m){
//             if(it.second>maxm){
//                 maxm=it.second;
//                 node=it.first;
//             }
            
//         }
//         return node;
        
    }
};