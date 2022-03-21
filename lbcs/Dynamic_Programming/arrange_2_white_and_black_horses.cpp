#include <bits/stdc++.h>
using namespace std;

/*
You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
Example:


Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option.

If a solution is not possible, then return -1
*/

int solve(int i, int k, int n, string A, vector<vector<int>> &t)
{
    if (i >= n && k > 0)
        return INT_MAX / 2;
    if (t[i][k] != -1)
        return t[i][k];
    int w = 0, b = 0;
    if (k == 1)
    {
        for (int j = i; j < n; j++)
        {
            if (A[j] == 'W')
                w++;
            else
                b++;
        }
        return t[i][k] = b * w;
    }
    int ans = INT_MAX / 2;
    for (int j = i; j < n; j++)
    {
        if (A[j] == 'W')
            w++;
        else
            b++;
        int temp = w * b + solve(j + 1, k - 1, n, A, t);
        ans = min(temp, ans);
    }
    return t[i][k] = ans;
}
int arrange(string A, int B)
{
    if (B > A.size())
        return -1;
    vector<vector<int>> t(A.size() + 1, vector(B + 1, -1));
    return solve(0, B, A.size(), A, t);
}

/*

int Solution::arrange(string A, int B) {
    int n = A.length();
    int dp[n][B];   // dp[i][j] = minimum val of accommodation
                    // till i'th index of the string
                    // using j+1 number of stables.
                    // Final ans will be in dp[n-1][B-1]

    memset(dp, 0, sizeof dp);

    if(n<B) return -1;
    else if(n==B) return 0;

    // filling first column
    int wt=0, bk=0;
    for(int i=0; i<n; i++){
        if(A[i]=='B') bk++;
        else wt++;
        dp[i][0]=bk*wt;
    }

    for(int j=1; j<B; j++){
        for(int i=0; i<n; i++){
            wt=0, bk=0;
            dp[i][j]=INT_MAX;
            for(int k=i; k>=0; k--){
                if(A[k]=='B') bk++;
                else wt++;
                dp[i][j] = min(dp[i][j], bk*wt +   ((k-1>=0)?dp[k-1][j-1]:0)   );
            }
        }
    }

    return dp[n-1][B-1];
}


*/
