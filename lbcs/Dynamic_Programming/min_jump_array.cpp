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
// Dyanamic approach TC-O(N2)
/*


int Solution::jump(vector<int> &arr) {
    int n=arr.size();
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<i;j++){
            if(dp[j]!=INT_MAX){
                if((arr[j]+j)>=i&& (1+dp[j])<dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }

    }
    if(dp[n-1]==INT_MAX){
        return -1;
    }
    return dp[n-1];


}

//Tc-O(N) SC-O(1)


int Solution::jump(vector<int> &arr) {
    int n=arr.size();
    int maxR=arr[0];
    int step=arr[0];
    int jump=1;
    if(n==1){
        return 0;
    }else if(arr[0]==0){
        return -1;
    }else{
        for(int i=1;i<n;i++){
            if(i==n-1){
                return jump;
            }
            maxR=max(maxR,i+arr[i]);
            step--;
            if(step==0){
                jump++;
                if(maxR<=i){
                return -1;
            }
            step=maxR-i;
            }

        }
    }
    return jump;


}


*/