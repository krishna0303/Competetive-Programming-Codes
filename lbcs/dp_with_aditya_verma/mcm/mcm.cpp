#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve(int *arr, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for (int k = i; k < j - 1; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (temp < mn)
        {
            mn = temp;
        }
    }
    return dp[i][j] = mn;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(arr, 1, n - 1) << endl;
    return 0;
}