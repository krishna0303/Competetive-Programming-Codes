

#include <bits/stdc++.h>
using namespace std;

/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.

Example : itertools.combinations in python.

If you do, we will disqualify your submission retroactively and give you penalty points.
 */

void solve(vector<int> &arr, int i, int target, vector<int> &v, set<vector<int>> &ans)
{
    if (i == arr.size())
    {
        if (target == 0)
        {
            ans.insert(v);
        }

        return;
    }

    if (target >= arr[i])
    {
        v.push_back(arr[i]);
        solve(arr, i + 1, target - arr[i], v, ans);
        v.pop_back();
    }
    solve(arr, i + 1, target, v, ans);
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> ans;
    vector<int> v;
    set<vector<int>> st;
    sort(A.begin(), A.end());
    solve(A, 0, B, v, st);

    for (auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}
