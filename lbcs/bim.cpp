

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};



int indx = 0;
unordered_map<int, int> m;
Node *construct(int in[], int pre[], int low, int high)
{
    if (low > high)
    {
        return NULL;
    }
    Node *res = new Node(pre[indx++]);
    if (low == high)
    {
        return res;
    }
    int mid = m[res->data];
    res->left = construct(in, pre, low, mid - 1);
    res->right = construct(in, pre, mid + 1, high);
    return res;
}
class Solution
{
public:
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code
        indx = 0;
        m.clear();
        for (int i = 0; i < n; i++)
        {
            m[in[i]] = i;
        }
        Node *res = construct(in, pre, 0, n - 1);
        return res;
    }
};

void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root);
    stack<vector<int>> ans;

    while (q.empty() == false)
    {
        int n = q.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            v.push_back(node->data);

            q.pop();

            if (node->left != NULL)
                q.push(node->left);

            if (node->right != NULL)
                q.push(node->right);
        }
        ans.push(v);
    }

    while (!ans.empty())
    {
        vector<int> v = ans.top();
        ans.pop();
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    
}
int main()
{

    int n;
    cin >> n;

    int inorder[n], preorder[n];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    Solution obj;
    Node *root = obj.buildTree(inorder, preorder, n);
    levelOrder(root);

    cout << endl;
}
