#include <bits/stdc++.h>

using namespace std;
#define INF INT_MAX
typedef long long int ll;
void bellman_ford(map<pair<int, int>, int> &edges,
                  vector<int> &dist,
                  int V)
{
    // int i = 1;
    for (int i = 1; i < V; i++)
    {
        
        for (auto e : edges)
        {

            int u = e.first.first;
            int v = e.first.second;
            int weight = e.second;
            if (dist[v] > dist[u] + (weight * (u + 1)))
            {
                dist[v] = dist[u] + (weight * (u + 1));
            }
        }
    }

    //this is for checkinng negative cycle if there is no cycle then this(dist[v] > dist[u] + weight)condition dosn't hold
    //it means means there is no further changes possible but if it hold this condition
    //it means  there is further changes possible so it is not accepted i.e there is negative cycle
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }
}

void addEdge(map<pair<int, int>, int> &edges,
             int u, int v, int w)
{
    edges[make_pair(u, v)] = w;
}
int main()
{

    ll V, E;
    cin >> V >> E;
    // vector<pair<ll,ll>> adj[V];
    // for (int i = 0; i < E; i++)
    // {
    //     ll u, v, w;
    //     cin >> u >> v >> w;
    //     adj[u - 1].push_back({v - 1, w});
    //     adj[v - 1].push_back({u - 1, w});
    // }
    map<pair<int, int>, int> edges;
    for (int i = 0; i < E; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        addEdge(edges, u - 1, v - 1, w);
        addEdge(edges, v - 1, u - 1, w);
    }

    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    bellman_ford(edges, dist, V);

    return 0;
} // } Driver Code Ends