#include <bits/stdc++.h>
using namespace std;

void topoSort(int src, vector<int> edges[], stack<int> &st, vector<bool> &visited)
{
    visited[src] = true;
    for (auto it : edges[src])
    {
        if (!visited[it])
        {
            topoSort(it, edges, st, visited);
        }
    }
    st.push(src);
}
void findSCC(int src, vector<int> transpose[], vector<bool> &visited, vector<int> &v)
{
    visited[src] = true;
    v.push_back(src);
    for (auto it : transpose[src])
    {
        if (!visited[it])
        {
            findSCC(it, transpose, visited, v);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &arr)
{
    // Write your code here.
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             cout<<edges[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    vector<int> edges[n];
    for (int i = 0; i < arr.size(); i++)
    {
        edges[arr[i][0]].push_back(arr[i][1]);
    }
    vector<bool> visited(n, false);
    vector<vector<int>> ans;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoSort(i, edges, st, visited);
        }
    }

    vector<int> transpose[n];

    for (int i = 0; i < n; i++)
    {
        for (auto it : edges[i])
        {
            transpose[it].push_back(i);
        }
    }
    //         visited.clear();
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    while (!st.empty())
    {
        int t = st.top();
        st.pop();
        vector<int> v;
        if (!visited[t])
        {
            findSCC(t, transpose, visited, v);
            ans.push_back(v);
        }
    }

    return ans;
}