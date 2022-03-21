
#include <bits/stdc++.h>
using namespace std;

/*

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/

class Solution
{
public:
    //using BFS
    bool isBipartiteUtil(int src, vector<vector<int>> &graph, vector<int> &visited)
    {
        queue<int> q;

        visited[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();

            q.pop();
            for (auto it : graph[node])
            {
                // cout<<it<<endl;
                if (visited[it] == -1)
                {
                    visited[it] = 1 - visited[node];
                    q.push(it);
                }
                else
                {
                    if (visited[it] == visited[node])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> visited(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i] == -1)
            {
                bool ans = isBipartiteUtil(i, graph, visited);
                if (!ans)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//using DFS
class Solution
{
public:
    bool isBipartiteUtil(int src, int color, vector<vector<int>> &graph, vector<int> &visited)
    {

        visited[src] = color;
        for (auto it : graph[src])
        {
            if (visited[it] == -1)
            {
                if (!(isBipartiteUtil(it, 1 - color, graph, visited)))
                {
                    return false;
                }
            }
            else
            {
                if (color == visited[it])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> visited(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i] == -1)
            {
                bool ans = isBipartiteUtil(i, 0, graph, visited);
                if (!ans)
                {
                    return false;
                }
            }
        }
        return true;
    }
};