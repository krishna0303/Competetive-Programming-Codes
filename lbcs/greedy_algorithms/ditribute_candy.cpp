

#include <bits/stdc++.h>
using namespace std;

/*

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.
Example:

Input 1:
    A = [1, 2]

Output 1:
    3

Explanation 1:
    The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor.
    So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

Input 2:
    A = [1, 5, 2, 1]

Output 2:
    7

Explanation 2:
    Candies given = [1, 3, 2, 1]


*/
int candy(vector<int> &A)
{
    int n = A.size();
    vector<int> left(n, 1), right(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (A[i - 1] < A[i])
        {
            left[i] = 1 + left[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] > A[i + 1])
        {
            right[i] = 1 + right[i + 1];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += max(left[i], right[i]);
    }
    return res;
}

/*

same approach as above just using the same array to find left and right

int Solution::candy(vector<int> &A) {
    int n=A.size();
    assert(n>=1);
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=1;
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[i-1])
            dp[i]=dp[i-1]+1;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]>A[i+1] && dp[i]<=dp[i+1]+1)
        {
            dp[i]=dp[i+1] + 1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=dp[i];
    return ans;
}


*/
