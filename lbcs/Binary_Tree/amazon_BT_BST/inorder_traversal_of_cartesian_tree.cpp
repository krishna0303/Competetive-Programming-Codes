#include <bits/stdc++.h>
using namespace std;

/*
Given an inorder traversal of a cartesian tree, construct the tree.

Cartesian tree :  is a heap ordered binary tree, where the root is greater than all the elements in the subtree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input : [1 2 3]

Return :
          3
         /
        2
       /
      1
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

TreeNode *solve(vector<int> &A, int s, int e)
{
    if (s > e)
        return NULL;
    int ind = -1, maxi = INT_MIN;
    for (int i = s; i <= e; i++)
    {
        if (A[i] > maxi)
        {
            maxi = A[i];
            ind = i;
        }
    }

    TreeNode *root = new TreeNode(A[ind]);
    root->left = solve(A, s, ind - 1);
    root->right = solve(A, ind + 1, e);
    return root;
}

TreeNode *buildTree(vector<int> &A)
{
    return solve(A, 0, A.size() - 1);
}
