#include <bits/stdc++.h>
using namespace std;

/*

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :

If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]


*/

void solve(vector<int> &arr, int i, int n, vector<int> v, set<vector<int>> &ans)
{
    if (i == n)
    {
        ans.insert(v);
        return;
    }
    solve(arr, i + 1, n, v, ans);
    v.push_back(arr[i]);
    solve(arr, i + 1, n, v, ans);
    v.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int> &A)
{
    vector<int> v;
    vector<vector<int>> ans;
    set<vector<int>> st;
    sort(A.begin(), A.end());
    solve(A, 0, A.size(), v, st);

    // sort(ans.begin(),ans.end());
    for (auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}
