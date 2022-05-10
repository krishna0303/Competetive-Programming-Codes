
#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given a binary tree A with N nodes.

You have to remove all the half nodes and return the final binary tree.

NOTE:

Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *solve(TreeNode *root)
{
    if (!root)
    {
        return root;
    }
    if (!root->left && root->right)
    {

        return root->right = solve(root->right);
    }
    if ((root->left && !root->right))
    {
        return root->left = solve(root->left);
    }
    root->left = solve(root->left);
    root->right = solve(root->right);
    return root;
}