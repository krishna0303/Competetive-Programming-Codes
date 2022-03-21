// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

 // } Driver Code Ends

   
    vector <ll> dijkstra(ll V, vector<vector<ll>> adj[], ll S,vector<pair<ll,ll>>&cost)
    {
        // Code here
        vector<ll>distance(V,LLONG_MAX);
        vector<bool>visited(V,false);
        distance[S]=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        
        pq.push({0,S});
        while(!pq.empty()){
            ll node=pq.top().second;
            ll weight=pq.top().first;
            // cout<<weight<<endl;
            visited[node]=true;
            pq.pop();
            for(auto it:adj[node]){
                if(!visited[it[0]]){
                    if(weight+(cost[node].second+(cost[node].first*it[1]))<distance[it[0]]){
                    distance[it[0]]=weight+(cost[node].second+(cost[node].first*it[1]));
                    pq.push({distance[it[0]],it[0]});
                    // cout<<weight+(cost[node].second+(cost[node].first*it[1]))<<endl;
                }
                    
                }
                
                
            }
        }
        return distance;
    }
        



// { Driver Code Starts.


int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>>adj[n];
    for(ll i=0;i<n-1;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        vector<ll>temp1,temp2;
        temp1.push_back(u-1);
        temp2.push_back(v-1);
        temp1.push_back(w);
        temp2.push_back(w);
        adj[v-1].push_back(temp1);
        adj[u-1].push_back(temp2);
        
    }
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    vector<ll>ans=dijkstra(n,adj,0,v);
    for(ll i=1;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}

  // } Driver Code Ends