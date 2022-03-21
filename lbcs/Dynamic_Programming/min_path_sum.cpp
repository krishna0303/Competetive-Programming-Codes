#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time.



Input Format
First and only argument is an 2D integer array A of size M x N.



Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).

*/

// recursive approach

//  int solve(vector<vector<int> > &mat,int i,int j,int **visited){
//     if(i<0||j<0||i>=mat.size()||j>=mat[0].size()){
//         return INT_MAX;
//     }

//     if((i==mat.size()-1)&&(j==mat[0].size()-1)){
//         return mat[i][j];
//     }
//     if(visited[i][j]!=-1){
//         return visited[i][j];
//     }
//     visited[i][j]=1;
//     int a=solve(mat,i+1,j,visited);
//     int b=solve(mat,i,j+1,visited);
//     int minm=min(a,b);
//     if(minm==INT_MAX){
//         return visited[i][j]=mat[i][j];

//     }
//     return visited[i][j]=mat[i][j]+minm;
// }

// int Solution::minPathSum(vector<vector<int> > &A) {

//      int **dp=new int*[A.size()];
//     for(int i=0;i<A.size();i++){
//         dp[i]=new int[A[0].size()];
//         for(int j=0;j<A[0].size();j++){
//             dp[i][j]=-1;
//         }

//     }
//     // memset(dp,0,sizeof(dp));
//     return solve(A,0,0,dp);

//     }
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];

        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};