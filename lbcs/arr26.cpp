
// Given an array of positive and negative numbers. 
// Find if there is a subarray (of size at-least one) with 0 sum.



#include<bits/stdc++.h>
using namespace std;


bool subarraySumZero(int *arr, int n){
     set<int>s;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(s.find(sum)!=s.end()){
            return true;
        }else if(sum==0){
            return true;
            
        }else{
            s.insert(sum);
        }
    }
    
    return false;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(subarraySumZero(arr,n)){
        cout<<"Yes\n";

    }else{
        cout<<"No\n";
    }
    



    return 0;
}

//Geeks For Geeks Code

/*
// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        set<int>s;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(s.find(sum)!=s.end()){
            return true;
        }else if(sum==0){
            return true;
            
        }else{
            s.insert(sum);
        }
    }
    
    return false;
        
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends
*/