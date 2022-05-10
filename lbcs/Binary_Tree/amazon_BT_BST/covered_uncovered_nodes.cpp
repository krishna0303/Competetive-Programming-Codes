

#include <bits/stdc++.h>
using namespace std;

/*
ou are given the root of a binary tree A, you need to return the absolute difference between sum of all covered elements and the sum of all uncovered elements.

In a binary tree, a node is called Uncovered if it appears either on left boundary or right boundary. Rest of the nodes are called covered.



Problem Constraints
1 <= Number of nodes in the binary tree <= 105


Input Format
The first argument is the root of the binary tree A.


Output Format
Return a single integer denoting the absolute difference of the sum of covered and uncovered nodes.


Example Input
Input 1:
    2
   / \
  1   4
 /   / \
6  10   5
Input 2:

      1
     /
    2
   /
  3


Example Output
Output 1:
8
Output 2:

6


Example Explanation
Explanation 1:
The node with value 10 is the only covered node. All other nodes are uncovered.
Therefore, the absolute difference is |(10) - (2 + 1 + 4 + 6 + 5)| = 8
Explanation 2:

All the given nodes are uncovered. Hence, the answer is sum of given nodes - 6.


*/

// this problem is same as burn tree with little variation

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
long coveredNodes(TreeNode *A)
{
    queue<TreeNode *> q;
    long sum = 0;
    long unc = 0;
    q.push(A);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (i == 0 || i == n - 1)
            {
                unc += temp->val;
            }
            sum += temp->val;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    // cout<<sum<<" "<<unc<<endl;
    if (sum == unc)
    {
        return sum;
    }
    return abs(unc - abs(sum - unc));
}
