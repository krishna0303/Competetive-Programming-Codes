

#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given a binary search tree A, where each node contains a positive integer, and an integer B, you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.

Return 1 to denote that two such nodes exist. Return 0, otherwise.



Problem Constraints
1 <= size of tree <= 100000

1 <= B <= 109
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTiterator
{
    stack<TreeNode *> st;
    bool reverse = true;

public:
    BSTiterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext()
    {
        return !st.empty();
    }
    int next()
    {
        TreeNode *temp = st.top();

        st.pop();
        if (reverse)
        {
            pushAll(temp->left);
        }
        else
        {
            pushAll(temp->right);
        }
        return temp->val;
    }

private:
    void pushAll(TreeNode *root)
    {
        if (reverse)
        {
            while (root != NULL)
            {
                st.push(root);
                root = root->right;
            }
        }
        else
        {
            while (root != NULL)
            {
                st.push(root);
                root = root->left;
            }
        }
    }
};

int t2Sum(TreeNode *A, int B)
{
    if (!A)
    {
        return 0;
    }
    BSTiterator l(A, false);
    BSTiterator r(A, true);
    int i = l.next();
    int j = r.next();
    while (i < j)
    {
        if (i + j == B)
        {
            return 1;
        }
        else if ((i + j) > B)
        {
            j = r.next();
        }
        else
        {
            i = l.next();
        }
    }
    return 0;
}
