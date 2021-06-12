#include<bits/stdc++.h>
using namespace std;

/*
 This task is similar as Activity Selection Problem. So, for n platforms we will simply make n-vectors 
 and put the respective trains in those vectors according to platform number. After that by applying 
 greedy approach we easily solve this problem.
Note : We will take input in form of 4-digit integer for arrival and departure time as 1030 will
 represent 10:30 so that we may handle the data type easily.
Also, we will choose a 2-D array for input as arr[m][3] where arr[i][0] denotes arrival time, 
arr[i][1] denotes departure time and arr[i][2] denotes the platform for ith train.

*/

bool compare(const pair<int,int>&a,const pair<int,int>&b){
    if(a.second<b.second){
        return true;
    }else if(a.second==b.second){
        return a.first<b.first;
    }else{
        return false;
    }
}
int maxStoppage(int arr[][3],int n,int m){
    vector<pair<int,int>>v[n+1];
    
    for(int i=0;i<m;i++){
        v[arr[i][2]].push_back(make_pair(arr[i][0],arr[i][1]));
    }
    int count=0;
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end(),compare);
        if(v[i].size()>0){
               count+=1;
        }
        int last_visit=v[i][0].second;
        for(int j=1;j<v[i].size();j++){
            if(v[i][j].first>=last_visit){
                count+=1;
                last_visit=v[i][j].second;
            }
            
        }

    }
    return count;

}
int main(){

    int n,m;
    cin>>n>>m;
    int arr[m][3];
    for(int i=0;i<m;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    
    cout<<maxStoppage(arr,n,m);
    return 0;
}