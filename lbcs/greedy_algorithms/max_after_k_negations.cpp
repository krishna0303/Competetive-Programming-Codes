// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:

    //Using sorting working code

    // long long int maximizeSum(long long int a[], int n, int k)
    // {
    //    sort(a,a+n);
    //    for(int i=0;i<n;i++){
    //        if(a[i]<0&&k>0){
    //            a[i]=-a[i];
    //            k--;
    //        }
    //    }
    //    long long int sum=0;
    //    for(int i=0;i<n;i++){
    //        sum+=a[i];
    //    }
    //    int val=*min_element(a,a+n);
    //    if(k&1){
    //        sum-=(2*val);
    //    }
    //    return sum;
    // }

    //using min heap
    long long int maximizeSum(long long int a[], int n, int k)
    {
       priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
       for(long long int i=0;i<n;i++){
           pq.push(a[i]);
       }
       while(k--){
           long long int t=pq.top();
           pq.pop();
           pq.push((-1)*t);
           
       }
       long long int sum=0;
       while(!pq.empty()){
           sum+=pq.top();
           pq.pop();
       }
       return sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends