

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
vector<int> morrisInorder(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode *rightMost = curr->left;
            while (rightMost->right != NULL && rightMost->right != curr)
            {
                rightMost = rightMost->right;
            }
            if (rightMost->right == NULL)
            {
                rightMost->right = curr;
                curr = curr->left;
            }
            else
            {
                ans.push_back(curr->data);
                rightMost->right = NULL;
                curr = curr->right;
            }
        }
    }
}

vector<int> morrispreOrder(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode *rightMost = curr->left;
            while (rightMost->right != NULL && rightMost->right != curr)
            {
                rightMost = rightMost->right;
            }
            if (rightMost->right == NULL)
            {
                rightMost->right = curr;
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else
            {

                rightMost->right = NULL;
                curr = curr->right;
            }
        }
    }
}