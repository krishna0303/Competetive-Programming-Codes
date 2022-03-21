#include <bits/stdc++.h>
using namespace std;

//Using BFS Kahn's Algorithm

class Solution
{
public:
    bool canFinishUtil(int numCourseId, vector<int> g[], int numCourses, vector<bool> &visited)
    {

        vector<int> inorder(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto &it : g[i])
            {
                inorder[it] += 1;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inorder[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : g[node])
            {
                inorder[it] -= 1;
                if (inorder[it] == 0)
                {
                    q.push(it);
                }
            }
            count += 1;
        }
        if (count == numCourses)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    //Using DFS
    //  bool canFinishUtil(int numCourseId, vector<int>g[],int numCourses,vector<bool>&visited,vector<bool>&order) {
    //     visited[numCourseId]=true;
    //      order[numCourseId]=true;
    //      for(auto it:g[numCourseId]){
    //          if(!visited[it]){
    //              if(canFinishUtil(it,g,numCourses,visited,order)) return true;
    //          }else{
    //              if(order[it]){
    //                  return true;
    //              }
    //          }
    //      }
    //      order[numCourseId]=false;
    //      return false;

    // }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> g[numCourses];
        for (int i = 0; i < prerequisites.size(); i++)
        {

            // g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                bool ans = canFinishUtil(i, g, numCourses, visited);
                if (ans)
                {
                    return false;
                }
            }
        }
        return true;
    }
};