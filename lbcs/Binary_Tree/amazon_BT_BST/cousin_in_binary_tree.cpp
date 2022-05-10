#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.

Cousin Tree:
Two nodes of a binary tree are cousins if they have the same depth or level,
but have different parents. No two nodes in the given binary tree will have the same data values.
*/

/*

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> solve(TreeNode *A, int B)
{
    if (A == NULL || B == A->val)
        return {};
    bool found = 0;
    queue<TreeNode *> q;
    q.push(A);
    while (q.size() && !found)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *p = q.front();
            if (p->right && p->right->val == B || (p->left && p->left->val == B))
                found = 1;
            else
            {
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            q.pop();
        }
    }
    vector<int> ans;
    while (q.size())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}