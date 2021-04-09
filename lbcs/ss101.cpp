// { Driver Code Starts

// Given a sorted array arr containing n elements with possibly
//  duplicate elements, the task is to find indexes of first and last occurrences of an element
//   x in the given array.


#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );



// } Driver Code Ends

int binarySearch1(int arr[], int i, int j, int x){
    int index=-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(arr[mid]==x){
            index=mid;
            j-=1;
            
            
        }else if(arr[mid]>x){
            j=j-1;
        }else{
            i+=1;
        }
    }
    return index;
}
int binarySearch2(int arr[], int i, int j, int x){
    int index=-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(arr[mid]==x){
            index=mid;
            i+=1;
            
            
        }else if(arr[mid]>x){
            j=j-1;
        }else{
            i+=1;
        }
    }
    return index;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>v;
    int ans1=binarySearch1(arr,0,n-1,x);
    v.push_back(ans1);
    int ans2=binarySearch2(arr,0,n-1,x);
    v.push_back(ans2);
    return v;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
