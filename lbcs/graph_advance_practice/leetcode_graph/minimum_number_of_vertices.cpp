
#include <bits/stdc++.h>
using namespace std;
/*
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.

 

Example 1:



Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].

*/
class Solution
{
public:
    void dfs(int src, vector<int> edges[], vector<bool> &visited)
    {
        visited[src] = true;
        for (auto it : edges[src])
        {
            if (!visited[it])
            {
                dfs(it, edges, visited);
            }
        }
    }
    void topoSort(int src, vector<int> edges[], vector<bool> &visited, stack<int> &s)
    {
        visited[src] = true;
        for (auto it : edges[src])
        {
            if (!visited[it])
            {
                dfs(it, edges, visited);
            }
        }
        s.push(src);
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> ans;
        vector<bool> visited(n, false);
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
        }
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                topoSort(i, adj, visited, s);
            }
        }
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        while (!s.empty())
        {
            int i = s.top();
            s.pop();
            if (!visited[i])
            {
                ans.push_back(i);
                dfs(i, adj, visited);
            }
        }
        return ans;
    }
};