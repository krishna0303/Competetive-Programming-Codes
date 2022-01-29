#include <bits/stdc++.h>
using namespace std;

/*

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

*/

class Solution
{
public:
    void dfs(int src, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[src] = true;
        for (int i = 0; i < isConnected[src].size(); i++)
        {
            if (isConnected[src][i] && !visited[i])
            {
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count += 1;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};