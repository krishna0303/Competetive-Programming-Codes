
#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given a binary tree, return the Postorder traversal of its nodes values.

NOTE: Using recursion is not allowed.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> postorderTraversal(TreeNode *A)
{
    vector<int> ans;
    stack<int> s1;
    stack<TreeNode *> st;
    TreeNode *curr = A;
    while (!st.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            s1.push(curr->val);
            if (curr->left)
            {
                st.push(curr->left);
            }
            curr = curr->right;
        }
        else
        {
            curr = st.top();
            st.pop();
        }
    }
    while (!s1.empty())
    {
        ans.push_back(s1.top());
        s1.pop();
    }
    return ans;
}