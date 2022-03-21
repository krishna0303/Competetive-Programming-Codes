#include <bits/stdc++.h>
using namespace std;

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
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

TreeNode *solve(vector<int> &A, vector<int> &B, int &index, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int ind = -1;
    for (int i = s; i <= e; i++)
    {
        if (B[i] == A[index])
        {
            ind = i;
            break;
        }
    }
    index++;

    TreeNode *root = new TreeNode(B[ind]);
    root->left = solve(A, B, index, s, ind - 1);
    root->right = solve(A, B, index, ind + 1, e);
    return root;
}
TreeNode *buildTree(vector<int> &A, vector<int> &B)
{
    int index = 0;
    return solve(A, B, index, 0, A.size() - 1);
}
