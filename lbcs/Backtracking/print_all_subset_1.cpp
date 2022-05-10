

#include <bits/stdc++.h>
using namespace std;

/*
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
 */

void solve(vector<int> &arr, int i, int n, vector<int> v, vector<vector<int>> &ans)
{
    if (i == n)
    {
        ans.push_back(v);
        return;
    }
    solve(arr, i + 1, n, v, ans);
    v.push_back(arr[i]);
    solve(arr, i + 1, n, v, ans);
    v.pop_back();
}

vector<vector<int>> subsets(vector<int> &A)
{
    vector<int> v;
    vector<vector<int>> ans;

    sort(A.begin(), A.end());
    solve(A, 0, A.size(), v, ans);

    sort(ans.begin(), ans.end());
    return ans;
}
