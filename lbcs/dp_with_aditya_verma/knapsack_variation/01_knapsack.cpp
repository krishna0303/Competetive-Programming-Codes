#include <bits/stdc++.h>
using namespace std;

/*

To identify dp problem:
1)choice like select or not
2)optimal like maximize, minimise ,largest,etc.

To solve dp problem:

Recursive -> Memoization -> Top-Down approach(iterative or tabular)

To get base condition:
Think about all smallest valid input


*/

int dp[102][1002];

int knapsack_recursive(int *item, int *val, int w, int n)
{
    if (n == 0 || w == 0)
    {
        return dp[n][w] = 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (item[n - 1] <= w)
    {
        return dp[n][w] = max(val[n - 1] + knapsack_recursive(item, val, w - item[n - 1], n - 1), knapsack_recursive(item, val, w, n - 1));
    }
    else if (item[n - 1] > w)
    {
        return dp[n][w] = knapsack_recursive(item, val, w, n - 1);
    }
}

int knapsack_iterative(int *item, int *val, int w, int n)
{
    int t[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(item[i]<=j){
                t[i][j]=max(val[i]+t[i-1][j-item[i]],t[i-1][j]);

            }else{
                t[i][j]=t[i-1][j];

            }
        }
    }
    return t[n][w];
}

int main()
{
    int n, w;
    cin >> n >> w;
    int *item = new int[n];
    int *val = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> item[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    memset(dp, -1, sizeof(dp));
    int maxProfit = knapsack_recursive(item, val, w, n);
    cout << maxProfit << endl;

    return 0;
}