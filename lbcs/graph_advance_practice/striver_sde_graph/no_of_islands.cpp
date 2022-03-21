#include <bits/stdc++.h>
using namespace std;

/*

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution
{
public:
    void drwTreeForComponent(vector<vector<char>> &arr, int i, int j, bool **visited)
    {
        if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || visited[i][j] == true || arr[i][j] == '0')
        {
            return;
        }
        visited[i][j] = true;
        drwTreeForComponent(arr, i - 1, j, visited);
        drwTreeForComponent(arr, i + 1, j, visited);
        drwTreeForComponent(arr, i, j - 1, visited);
        drwTreeForComponent(arr, i, j + 1, visited);
    }
    int numIslands(vector<vector<char>> &arr)
    {
        int count = 0;
        bool **visited = new bool *[arr.size()];
        for (int i = 0; i < arr.size(); i++)
        {
            visited[i] = new bool[arr[0].size()];
            for (int j = 0; j < arr[0].size(); j++)
            {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                if (arr[i][j] == '1' && !visited[i][j])
                {
                    drwTreeForComponent(arr, i, j, visited);
                    count += 1;
                }
            }
        }
        return count;
    }
};