#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;



// this is also working dijkstra's algorithm but TC-O(n*n)
// int get_min_vertex(bool *visited, int *distance, int V) {
// 	int min_vertex = -1;

// 	for (int i = 0; i < V; i++) {
// 		if ((!visited[i]) && ((min_vertex == -1) || distance[i] < distance[min_vertex])) {
// 			min_vertex = i;
// 		}
// 	}
	
// 	return min_vertex;
// }


// void dijkstras(int **edge, int V) {
// 	bool *visited = new bool [V]();
// 	int *distance = new int [V];

// 	distance[0] = 0;
// 	for (int i = 1; i < V; i++) {
// 		distance[i] = INT_MAX;
// 	}

// 	for (int i = 0; i < V - 1; i++) {
// 		int min_vertex = get_min_vertex(visited, distance, V);
// 		visited[min_vertex] = true;

// 		for (int  j = 0; j < V; j++) {
// 			if (min_vertex == j) continue;
// 			if (edge[min_vertex][j] && (!visited[j])) {
// 				if ((edge[min_vertex][j] + distance[min_vertex]) < distance[j]) {
// 					distance[j] = edge[min_vertex][j] + distance[min_vertex];
// 				}
// 			}
// 		}
		
// 	}

// 	for (int i = 0; i < V; ++i) {
// 		cout << i << " " << distance[i] << "\n";
// 	}
	
// 	delete [] visited;
// 	delete [] distance;
// }


// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int V, E;
//     cin >> V >> E;
//     int **edge = new int *[V];

//     for (int i = 0; i < V; i++) {
//     	edge[i] = new int [V];
//     }
    
//     int start, end, weight;
//     for (int i = 0; i < E; i++) {
// 		cin >> start >> end >> weight;
// 		edge[start][end] = weight;
// 		edge[end][start] = weight;
//     }
    
//     dijkstras(edge, V);

//     for (int i = 0; i < V; i++) {
//     	delete [] edge[i];
//     }
//     delete [] edge;

//     return 0;
// }

//Dijkstra's algorithm with TC-nlogn by using min_heap priority queue or set



#include<bits/stdc++.h>

using namespace std;
#define INF 9999999



 //for better understanding watch striver video

class Solution {
public:

   /*
   this is similar to shportest path undirected graph only difference here is we are using priority queue but we have not used priority queue
   in shortest path because we their we have assume weight is 1 or equal so there is no need to use priority queue we can't get
   benefit of priority queue but if weight of edges are different then we can use priority queue and we are reducing time
   in dijkstra's we are using min_ heap priority queue which help to provide the min dist node among all the nodes
   so we have to first update that node so that it's changes can come in next nodes but it we updated any random nodes then there is
   chance that we hvae to visit one node again and again if lowst distance nodes will come and due to this we have to agin update its adjacent nodes and so on
   priority queue is helping in minimum distance node so that we can update it first
   
   
   */

    
    

    
	int Dijkstras_Algorithm(int V, vector<pair<int,int>>adj[],int src,int dst){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		
        vector<int>distance(V,INF);
        distance[src]=0;
		pq.push({0,src});

        while(!pq.empty()){
            int node=pq.top().second;
			int dist=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                
				if((dist+it.second)<distance[it.first]){
                    distance[it.first]=dist+it.second;
					pq.push(make_pair(distance[it.first],it.first));
                }

                
               
            }

        }
        for(int i=0;i<V;i++){
            cout<<distance[i]<<" ";
        }
        cout<<endl;

		return distance[dst];

	    
	    

	}
    

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<pair<int,int>>adj[V];
		for(int i = 0; i < E; i++){
			int u, v,w;
			cin >> u >> v>>w;
			adj[u-1].push_back({v-1,w});
			
		}
        int src,dst;
        cin>>src>>dst;
		Solution obj;
		 cout<<obj.Dijkstras_Algorithm(V, adj,src,dst)<<endl;    
		
	}
	return 0;
}  // } Driver Code Ends