#include <bits/stdc++.h>

using namespace std;
#define INF INT_MAX
typedef long long int ll;

int bellman_ford(map<pair<char, char>, int> &edges,
                 map<char, int> &dist,
                 int V, map<char, int> &m)
{

    for (int i = 1; i < V; i++)
    {

        for (auto e : edges)
        {

            char u = e.first.first;
            char v = e.first.second;
            int weight = e.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    //this is for checkinng negative cycle if there is no cycle then this(dist[v] > dist[u] + weight)condition dosn't hold
    //it means means there is no further changes possible but if it hold this condition
    //it means  there is further changes possible so it is not accepted i.e there is negative cycle
    int count = 0;
    for (auto it : dist)
    {
        if (it.second == INT_MAX)
        {
            count = INT_MAX;
            break;
        }
        else
        {
            count += (it.second * m[it.first]);
        }
    }
    return count;
}

void addEdge(map<pair<char, char>, int> &edges,
             char u, char v, int w)
{
    edges[make_pair(u, v)] = w;
}
int main()
{
    //     #ifndef ONLINE_JUDGE

    //     // For getting input from input.txt file
    //     freopen("consistency_chapter_1_input.txt", "r", stdin);

    //     // Printing the Output to output.txt file
    //     freopen("output_chapter_1.txt", "w", stdout);

    // #endif

    int t;
    cin >> t;
    int k = 1;
    while (k <= t)
    {
        int E;
        string s;
        cin >> s;
        cin >> E;
        map<char, int> m;

        map<pair<char, char>, int> edges;
        for (int i = 0; i < E; i++)
        {

            string st;
            cin >> st;
            addEdge(edges, st[0], st[1], 1);
        }
        // int ans = INT_MAX;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]] += 1;
        }
        int ans = INT_MAX;
        if (m.size() == 1)
        {
            ans = 0;
        }
        else
        {

            for (int i = 0; i < s.length(); i++)
            {

                map<char, int> dist;
                for (int j = 0; j < s.length(); j++)
                {
                    dist[s[j]] = INT_MAX;
                }
                dist[s[i]] = 0;
                int count = bellman_ford(edges, dist, s.length(), m);
                // cout << count << endl;
                if (count < ans)
                {
                    ans = count;
                }
            }
        }
        if (ans == INT_MAX)
        {
            ans = -1;
        }
        cout << "Case #" << k << ": " << ans << endl;
        k++;
    }

    return 0;
} // } Driver Code Ends