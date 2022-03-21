

#include <bits/stdc++.h>
using namespace std;

/*
Given numRows, generate the first numRows of Pascal's triangle.
Pascal's triangle : To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
Constraints:
0 <= numRows <= 25


*/

vector<vector<int>> solve(int A)
{
    vector<vector<int>> ans;
    if (A == 0)
    {
        return ans;
    }

    vector<int> temp;
    temp.push_back(1);
    ans.push_back(temp);
    for (int i = 1; i < A; i++)
    {
        vector<int> v = ans[ans.size() - 1];
        v.push_back(0);
        vector<int> v1 = v;
        for (int j = 1; j < v.size(); j++)
        {
            v[j] = v[j] + v1[j - 1];
        }
        ans.push_back(v);
    }
    return ans;
}
