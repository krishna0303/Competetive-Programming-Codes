#include<bits/stdc++.h>
using namespace std;



/*

Applications: 
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs.
 In computer science, applications of this type arise in instruction scheduling, ordering of formula cell 
 evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation 
 tasks to perform in make files,
 data serialization, and resolving symbol dependencies in linkers
*/
int checkIndegreeZero(map<int,int>m){
    for(auto x:m){
        if(x.second==0){
            return x.first;
        }
    } 
    return -1;
    
}

/*
Algorithm: Steps involved in finding the topological ordering of a DAG:
Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.

Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
Step 5: Repeat Step 3 until the queue is empty.

*/

void kahnS_algo(int **edges,int n){
    vector<int>ans;
    queue<int>q;
    map<int,int>m;
    for(int i=0;i<n;i++){
        m[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]){
                m[j]+=1;

      
            }
        }
    }
    

    int val=checkIndegreeZero(m);
    // cout<<val<<endl;
    if(val!=-1){
        q.push(val);
        m[val]=-1;
    }
    while(!q.empty()){
        int v=q.front();
        q.pop();
        ans.push_back(v);
        for(int i=0;i<n;i++){
            if(i==v){
                continue;
            }
            if(edges[v][i]){
                m[i]-=1;
                int val1=checkIndegreeZero(m);
                if(val1!=-1){
                    q.push(val1);
                    m[val1]=-1;
                }
                
            }
        }
        
    }
    // for(int i=0;i<ans.size();i++){
    //         cout<<ans[i]<<" ";
    //     }
    //   cout<<ans.size()<<endl;  
        
    if(ans.size()!=n){
        cout<<"This is not a directed acyclic graph i.e there exist cycle\n";

    }else{
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    

}
void topological_sort(int**edges,int n,int sv,vector<int>&ans,bool *visited){
     visited[sv]=true;
     for(int i=0;i<n;i++){
         if(i==sv){
             continue;
         }
         if(edges[sv][i]&&(!visited[i])){
             topological_sort(edges,n,i,ans,visited);
         }
     }
     ans.push_back(sv);
}

void modified_dfs(int **edges,int n){
    vector<int>ans;
    bool *visited=new bool[n]();
    topological_sort(edges,n,0,ans,visited);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";

    }
    cout<<endl;


}
int main(){

    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
        
    }
    for(int j=0;j<e;j++){
            int u,v;
            cin>>u>>v;
            edges[u][v]=1;//because directed graph
            
    }
    kahnS_algo(edges,n);
    modified_dfs(edges,n);


    return 0;
}