#include <bits/stdc++.h>
using namespace std;

/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input :
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return :
            1
           / \
          2   3
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
    if (s > e || index < 0)
    {
        return NULL;
    }
    int ind = -1;
    for (int i = s; i <= e; i++)
    {
        if (B[index] == A[i])
        {
            ind = i;
            break;
        }
    }
    index--;
    TreeNode *root = new TreeNode(A[ind]);
    root->right = solve(A, B, index, ind + 1, e);
    root->left = solve(A, B, index, s, ind - 1);

    return root;
}
TreeNode *buildTree(vector<int> &A, vector<int> &B)
{

    int index = A.size() - 1;
    return solve(A, B, index, 0, A.size() - 1);
}
