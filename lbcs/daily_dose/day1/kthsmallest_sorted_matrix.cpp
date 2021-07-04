// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.


// Method1-NaiveApproach

// int kthSmallest(int **mat, int n, int k)
// {
//   //Your code here
//   vector<int>v;
//   for(int i=0;i<n;i++){
//       for(int j=0;j<n;j++){
//           v.push_back(mat[i][j]);
          
//       }
//   }
//   sort(v.begin(),v.end());
//   return v[k-1];
// }


//Heapify Method-Didn't understand

//for better understanding https://www.youtube.com/watch?v=dpsp1hP6P-U refer this video

int count(int **mat,int n,int num){
    int count=0;
    int j=n-1;
    for(int i=0;i<n;i++){
        for(j;j>=0;j--){
            if(mat[i][j]<=num){
                count+=(j+1);
                break;
            }
        }
    }
    return count;

}
void BinarySearch(int **mat,int low,int high,int n,int k,int &ans){
    while(low<high){
        int mid=(low+high)/2;
        int c=count(mat,n,mid);
        if(c<k){
            low=mid+1;
        }else{
            ans=mid;
            high=mid;
        }
    }
}

int kthSmallest(int **mat, int n, int k)
{
  //Your code here
  if(n==1&&k==1){
      return mat[0][0];
  }
  int low=mat[0][0];
  int high=mat[n-1][n-1];
  int ans=0;
  BinarySearch(mat,low,high,n,k,ans);
  return ans;
}


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