

#include <bits/stdc++.h>
using namespace std;

/*
Problem Description



Given the root of a binary tree A, the value of a target node B, and an integer C, return an array of the values of all nodes that have a distance C from the target node.

You can return the answer in any order.


Problem Constraints
1 ≤ N ≤ 105 (N is the number of nodes in the binary tree)
1 ≤ Ai ≤ N (Ai denotes the values of the nodes in the tree)
All the values in the nodes are unique.
1 ≤ C ≤ 104



*/


// this problem is same as burn tree with little variation

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> distanceK(TreeNode *A, int B, int C)
{
    map<TreeNode *, TreeNode *> m;
    queue<TreeNode *> q;
    TreeNode *start;
    q.push(A);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->val == B)
            {
                start = temp;
            }
            if (temp->left)
            {
                m[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                m[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    queue<TreeNode *> nq;
    nq.push(start);
    int count = 0;
    vector<int> visited(100001, -1);
    vector<int> ans;
    while (!nq.empty())
    {
        int n = nq.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = nq.front();
            nq.pop();
            visited[temp->val] = 1;
            if (count == C && visited[temp->val] == 1)
            {
                ans.push_back(temp->val);
                // cout<<n<<endl;
            }
            if (m.find(temp) != m.end())
            {
                TreeNode *parent = m[temp];
                if (visited[parent->val] == -1)
                {
                    visited[parent->val] = 1;
                    nq.push(parent);
                }
            }
            if ((temp->left && visited[temp->left->val] == -1))
            {
                visited[temp->left->val] = 1;
                nq.push(temp->left);
            }
            if (temp->right && visited[temp->right->val] == -1)
            {
                visited[temp->right->val] = 1;
                nq.push(temp->right);
            }
        }
        if (count == C)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    return ans;
}
