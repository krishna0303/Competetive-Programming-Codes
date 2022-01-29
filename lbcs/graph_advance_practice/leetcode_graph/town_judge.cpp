#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &edges)
    {
        // if(n==2){
        //     return edges[0][1];
        // }
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
        int node = -1;
        for (int i = 0; i < n; i++)
        {
            // cout<<node<<endl;
            if (adj[i].size() == (n - 1))
            {
                if (node == (-1))
                {
                    node = i;
                }
                else
                {
                    return -1;
                }
            }
        }
        if (node == -1)
        {
            return node;
        }
        for (int i = 0; i < n; i++)
        {
            if (i == node)
            {
                continue;
            }
            for (auto it : adj[i])
            {
                if (it == node)
                {
                    return -1;
                }
            }
        }
        return node + 1;
    }
};