// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
Given a weighted, directed and connected graph of V vertices and E edges, 
Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.



*/
// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    /*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>> adj, int S)
    {
        // Code here
        vector<int> distance(V, 100000000);
        distance[S] = 0;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj.size(); j++)
            {
                if (distance[adj[j][0]] + adj[j][2] < distance[adj[j][1]])
                {
                    distance[adj[j][1]] = distance[adj[j][0]] + adj[j][2];
                }
            }
        }
        return distance;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.bellman_ford(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends