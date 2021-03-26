// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.


// Method1-NaiveApproach

int kthSmallest(int **mat, int n, int k)
{
  //Your code here
  vector<int>v;
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          v.push_back(mat[i][j]);
          
      }
  }
  sort(v.begin(),v.end());
  return v[k-1];
}


//Heapify Method-Didn't understand


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<kthSmallest(arr,n,k)<<endl;

return 0;
}