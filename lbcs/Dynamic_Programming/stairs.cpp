#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

You are climbing a stair case and it takes A steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?





*/

// Tc-O(N) SC-O(1)

int climbStairs(int A)
{
    int dp[A + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= A; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[A];
}
