#include <bits/stdc++.h>
using namespace std;
/*
problem link and it  is tricky problem hai graph ka
https://leetcode.com/problems/regions-cut-by-slashes/



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
        if (rootY == rootX)
        {
            return;
        }
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
            {
                rank[rootX]++;
            }
        }
    }

    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        int m = n + 1;
        vector<int> parent(m * m);
        vector<int> rank(m * m, 0);
        make_parent(parent);
        int j = 1;
        for (int i = 0; i < m, j < m * m;)
        {

            if (i == 0 || i == m - 1)
            {
                set_union(parent, rank, 0, j);
                j++;
                if (j == m)
                {
                    i++;
                }
            }
            else
            {
                set_union(parent, rank, 0, j);
                j = j + n;
                set_union(parent, rank, 0, j);
                j++;
                i++;
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '/')
                {
                    int point1 = (i * m) + (j + 1);
                    int point2 = (i + 1) * m + j;
                    int par1 = findParent(parent, point1);
                    int par2 = findParent(parent, point2);
                    if (par1 == par2)
                    {
                        ans += 1;
                    }

                    set_union(parent, rank, point1, point2);
                }
                else if (grid[i][j] == '\\')
                {
                    int point1 = (i * m) + (j);
                    int point2 = (i + 1) * m + j + 1;
                    int par1 = findParent(parent, point1);
                    int par2 = findParent(parent, point2);
                    if (par1 == par2)
                    {
                        ans += 1;
                    }

                    set_union(parent, rank, point1, point2);
                }
            }
        }
        return ans;
    }
};