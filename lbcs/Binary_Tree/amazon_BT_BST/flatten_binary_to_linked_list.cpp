#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, flatten it to a linked list in-place.

Example :

Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.
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

TreeNode *solve(TreeNode *root)
{
    if (!root)
    {
        return NULL;
    }
    TreeNode *l = solve(root->left);
    TreeNode *r = solve(root->right);
    if ((!l && r) || (!l && !r))
    {
        return root;
    }
    TreeNode *temp = l;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    temp->right = r;
    root->right = l;
    root->left = NULL;
    return root;
}
TreeNode *flatten(TreeNode *A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return solve(A);
}
