
/*
Given arrival and departure times of all trains that reach a railway station. 
Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. 
Arrival and departure time can never be the same for a train but we can have arrival time of 
one train equal to departure time of the other. At any given instance of time, same platform can
 not be used for both departure of a train and arrival of another train. 
In such cases, we need different platforms,

Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.

*/

// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


/*

Algorithm

Sort the arrival and departure times of trains.
Create two pointers i=1(because consider one platform for first arrival train), and j=0 and a variable to store ans and current count plat
Run a loop while i<n and j<n and compare the ith element of arrival array and jth element of departure array.
If the arrival time is less than or equal to departure then one more platform is needed so increase the count, i.e. plat++ and increment i
Else if the arrival time greater than departure then one less platform is needed so decrease the count, i.e. plat– and increment j
Update the ans, i.e ans = max(ans, plat).


*/
 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1,j=0;
    	int plat_needed=1,result=1;
    	while(i<n&&j<n){
    	    if(arr[i]<=dep[j]){
    	        plat_needed+=1;
    	        i++;
    	    }else{
    	        plat_needed-=1;
    	        j++;
    	    }
    	    result=max(result,plat_needed);
    	}
    	return result;
    	
    	
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
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends