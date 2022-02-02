#include <bits/stdc++.h>
using namespace std;
/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
*/
class Solution
{
public:
    void make_parent(vector<int> &parent)
    {
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }
    }

    int findParent(vector<int> &parent, int x)
    {
        if (parent[x] != x)
        {
            parent[x] = findParent(parent, parent[x]);
        }
        return parent[x];
    }

    void set_union(vector<int> &parent, vector<int> &rank, int x, int y)
    {
        int rootX = findParent(parent, x);
        int rootY = findParent(parent, y);
        if (rootX == rootY)
        {
            return;
        }
        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootX] = rootY;
            if (rank[rootX] == rank[rootY])
            {
                rank[rootY]++;
            }
        }
    }
    void dfs(int src, vector<int> adj[], vector<bool> &visited)
    {
        visited[src] = true;
        for (auto it : adj[src])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int count = 0;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        make_parent(parent);
        vector<bool> visited(n, false);
        vector<int> adj[n];

        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                sum += 1;
                dfs(i, adj, visited);
            }
        }

        for (auto it : connections)
        {
            int x = findParent(parent, it[0]);
            int y = findParent(parent, it[1]);
            visited[it[0]] = true;
            visited[it[1]] = true;
            if (x == y)
            {
                count += 1;
            }
            else
            {
                set_union(parent, rank, it[0], it[1]);
            }
        }

        sum -= 1;
        if (sum > count)
        {
            return -1;
        }
        else
        {
            return min(sum, count);
        }
    }
};