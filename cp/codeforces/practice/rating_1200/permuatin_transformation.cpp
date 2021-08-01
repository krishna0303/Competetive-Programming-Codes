#include <bits/stdc++.h>
using namespace std;

/*

problem link:  https://codeforces.com/problemset/problem/1490/D


*/

int maxInRange(int *arr, int n, int low, int high)
{
    int maxm = INT_MIN;
    int index = -1;
    for (int i = low; i <= high; i++)
    {
        if (maxm < arr[i])
        {
            maxm = arr[i];
            index = i;
        }
    }
    return index;
}

void permuteTransform(int *arr, int n, int *ans, int depth, int low, int high, bool *visited)
{
    int ind = maxInRange(arr, n, low, high);
    ans[ind] = depth;
    visited[ind] = true;
    if ((ind - 1) >= 0 && !visited[ind - 1])
    {
        permuteTransform(arr, n, ans, depth + 1, low, ind - 1, visited);
    }
    if ((ind + 1) < n && !visited[ind + 1])
    {
        permuteTransform(arr, n, ans, depth + 1, ind + 1, high, visited);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int *ans = new int[n];
        for (int i = 0; i < n; i++)
        {
            ans[i] = 0;
        }
        bool *visited = new bool[n]();
        int index = 0;
        permuteTransform(arr, n, ans, 0, 0, n - 1, visited);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}