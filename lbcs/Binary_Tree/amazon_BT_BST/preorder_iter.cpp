#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.
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
vector<int> preorderTraversal(TreeNode *A)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *curr = A;
    while (!st.empty() || (curr != NULL))
    {
        if (curr != NULL)
        {
            ans.push_back(curr->val);
            if (curr->right)
            {
                st.push(curr->right);
            }
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
        }
    }
    return ans;
}
