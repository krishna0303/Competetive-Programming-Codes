#include <bits/stdc++.h>
using namespace std;
/*
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

It's a tricky problem or new concept which is marking negative direction


*/
class Solution
{
public:
    void dfs(int src, vector<int> adj[], vector<bool> &visited, int &count)
    {
        visited[src] = true;
        for (auto it : adj[src])
        {
            if (!visited[abs(it)])
            {

                dfs(abs(it), adj, visited, count);
                if (it > 0)
                {
                    count += 1;
                }
            }
        }
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<bool> visited(n, false);
        vector<int> adj[n];
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {

            if (!visited[abs(i)])
            {
                dfs(i, adj, visited, count);
            }
        }
        return count;
    }
};