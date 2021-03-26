// Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.
// Input:
// n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8
// Explanation: For the above test case the
// matrix will look like
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// the max size rectangle is 
// 1 1 1 1
// 1 1 1 1
// and area is 4 *2 = 8.

#include<bits/stdc++.h>
using namespace std;

int findHistArea(int *hist, int m){
    stack<int>s;
    int i=0;
    int maxVal=0;
    int smallArea=0;
    int tp;

    while(i<m){
        if(s.empty()||hist[s.top()]<=hist[i]){
            s.push(i++);
        }
        else{
            tp=s.top();
            s.pop();
            smallArea=hist[tp]*(s.empty()?i:i-s.top()-1);
            if(smallArea>maxVal){
                maxVal=smallArea;
            }
        }
    }
    while(s.empty()==false){
         tp=s.top();
            s.pop();
            smallArea=hist[tp]*(s.empty()?i:i-s.top()-1);
            if(smallArea>maxVal){
                maxVal=smallArea;
            }

    }
    return maxVal;
}

int findMaxArea(int **arr, int n,int m){
    int*hist=new int[m];
    for(int i=0;i<m;i++){
        hist[i]=0;
    }
    int maxArea=findHistArea(arr[0],m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                // hist[j]+=hist[j]+arr[i][j];
                arr[i][j]+=arr[i-1][j];
            }

        }
        int smallAns=findHistArea(arr[i],m);
        if(smallAns>maxArea){
            maxArea=smallAns;
        }


    }
    return maxArea;
}

int main(){
    int r,c;
    cin>>r>>c;
    int **arr=new int*[r];
    for(int i=0;i<r;i++){
        arr[i]=new int[c];
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    int ans= findMaxArea(arr,r,c);
    cout<<ans<<endl;
    return 0;
}