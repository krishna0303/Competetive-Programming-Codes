// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

/*
Sort the array by value by weigh ratio and select each item one by one till it's weight is lesser than target weight and 
if at any moment weight of ith index is greater than target weight then add value of remainng weight i.e fraction pof weight
value+=(weight/arr[i].weight)*arr[i].value and after that break the loop and return final answer

*/


bool compare(const Item &a,const Item &b){
    if(((double)a.value/(double)a.weight)>((double)b.value/(double)b.weight)){
        return true;
    }else{
        return false;
    }
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,compare);
        double val=0.0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<=W){
                val+=arr[i].value;
                W-=arr[i].weight;
                
                
                
            }else{
                val+=(arr[i].value*((double)W/(double)arr[i].weight));
                break;
            }
            
        }
        return val;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends