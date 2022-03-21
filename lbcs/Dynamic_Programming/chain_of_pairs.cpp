#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given an array A with non negative numbers, divide the array into two parts such that the average of both the parts is equal.

Return both parts (If exist). If there is no solution. return an empty list.

NOTE:

If a solution exists, you should return a list of exactly 2 lists of integers A and B which follow the following condition :
numElements in A <= numElements in B
If numElements in A = numElements in B, then A is lexicographically smaller than B ( https://en.wikipedia.org/wiki/Lexicographical_order )
If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest.

Array will contain only non negative numbers.



**Input Format**
First andonly argument is an integer array A.



**Output Format**
Return 2D array consisting of two rows where each row denoted a partition.



**Example Input**
Input 1:

 A = [1 7 15 29 11 9]


Example Output
Output 1:

 [9 15] [1 7 11 29]


Example Explanation
Explanation 1:

 The average of part is (15+9)/2 = 12, average of second part elements is (1 + 7 + 11 + 29) / 4 = 12



*/

// this is my solution  recursive solution
// int dp[1002][10002];

// int helper(vector<vector<int>> &A, int n, int curr)
// {
//     if (n == A.size())
//     {
//         return 0;
//     }
//     if (dp[n][curr] != -1)
//     {
//         return dp[n][curr];
//     }
//     if (curr < A[n][0])
//     {
//         return dp[n][curr] = max(1 + helper(A, n + 1, A[n][1]), helper(A, n + 1, curr));
//     }
//     else
//     {
//         return dp[n][curr] = helper(A, n + 1, curr);
//     }
// }

// int solve(vector<vector<int>> &A)
// {
//     memset(dp, -1, sizeof(dp));
//     return helper(A, 0, 0);
// }

// LIS solution
/*

int Solution::solve(vector<vector<int> > &A) {
    vector<int>dp(A.size(),1);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<i;j++){
            if(A[i][0]>A[j][1]) dp[i]=max(1+dp[j],dp[i]);
        }
    }
    return *max_element(dp.begin(),dp.end());
}
*/

/*

this is not working
bool compare(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end(),compare);
    int count=1;
    int last=A[0][1];
    for(int i=1;i<A.size();i++){
        if(A[i][0]>last){
            last=A[i][1];
            count++;
        }
    }
    return count;
}

*/
