#include <bits/stdc++.h>
using namespace std;

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : [1, 2, 3]
A height balanced BST  :

      2
    /   \
   1     3
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *solve(const vector<int> &A, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode *root = new TreeNode(A[mid]);
    root->left = solve(A, s, mid - 1);
    root->right = solve(A, mid + 1, e);
    return root;
}
TreeNode *sortedArrayToBST(const vector<int> &A)
{
    return solve(A, 0, A.size() - 1);
}
