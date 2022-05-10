

#include <bits/stdc++.h>
using namespace std;

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :

If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 */

void solve(int i, int n, int k, vector<int> v, vector<vector<int>> &ans, int count)
{
    if (count == k)
    {
        ans.push_back(v);
        return;
    }
    for (int j = i; j <= n; j++)
    {
        v.push_back(j);
        solve(j + 1, n, k, v, ans, count + 1);
        v.pop_back();
    }
}

vector<vector<int>> combine(int A, int B)
{

    vector<int> v;
    vector<vector<int>> ans;
    if (B > A)
    {
        return ans;
    }
    if (A == B)
    {
        for (int i = 1; i <= A; i++)
        {
            v.push_back(i);
        }
        ans.push_back(v);
        return ans;
    }
    solve(1, A, B, v, ans, 0);
    return ans;
}
