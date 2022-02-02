
#include <bits/stdc++.h>
using namespace std;
/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
*/
class Solution
{
public:
    double dfs(string src, string dst, map<string, bool> &visited, map<string, vector<pair<string, double>>> &m)
    {
        if (m.find(src) == m.end() || m.find(dst) == m.end())
        {
            return -1.0;
        }
        if (src.compare(dst) == 0)
        {
            return 1.0;
        }
        visited[src] = true;
        for (auto it : m[src])
        {
            // cout<<it.first<<endl;
            if (visited.find(it.first) == visited.end())
            {
                double val1 = dfs(it.first, dst, visited, m);
                if (val1 != (-1.0))
                {
                    return val1 * it.second;
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        map<string, vector<pair<string, double>>> m;
        for (int i = 0; i < equations.size(); i++)
        {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
            double val = values[i];
            if (m.find(s1) == m.end())
            {
                m[s1].push_back({s1, 1.00000});
            }

            m[s1].push_back({s2, val});
            if (m.find(s2) == m.end())
            {
                m[s2].push_back({s2, 1.00000});
            }

            m[s2].push_back({s1, 1 / val});
        }
        vector<double> ans;

        for (auto it : queries)
        {
            string s1 = it[0];
            string s2 = it[1];
            map<string, bool> visited;
            ans.push_back(dfs(s1, s2, visited, m));
        }
        return ans;
    }
};