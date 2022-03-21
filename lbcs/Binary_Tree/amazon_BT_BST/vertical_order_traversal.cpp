

#include <bits/stdc++.h>
using namespace std;

/*
Problem Description



Given a binary tree A consisting of N nodes, return a 2-D array denoting the vertical order traversal of A.

Go through the example and image for more details.

NOTE:

If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the level-order traversal of tree comes first in the output.
Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be the nodes on the rightmost vertical line.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>>verticalOrderTraversal(TreeNode *A)
{
    vector<vector<int>> ans;

    if (!A)
    {
        return ans;
    }
    queue<pair<TreeNode *, int>> q;
    map<int, vector<int>> m;

    q.push({A, 0});
    while (!q.empty())
    {
        TreeNode *root = q.front().first;
        int h = q.front().second;
        q.pop();
        m[h].push_back(root->val);
        if (root->left)
        {
            q.push({root->left, h - 1});
        }
        if (root->right)
        {
            q.push({root->right, h + 1});
        }
    }
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}
