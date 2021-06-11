/*
Given a set of N jobs where each job i has a deadline and profit associated to it. 
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum 
profit and the number of jobs done.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.

*/


// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool compare(const Job&a,const Job&b){
    if(a.profit>b.profit){
        return true;
    }else{
        return false;
    }
    
}

/*
first of all sort the array in decrerasing order of profit
then find maximum deadline and then create one visiwted arraty of size maxM and make all false
now iterate eelemtn one by one and check if its deadline is already visted or not if not then select it 
and if visited then go to backwards i.e previous deadline is there any slots available or any deadline available whose value is still fAlse
if found that index then also select it i. this job
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,compare);
        int maxM=INT_MIN;
        for(int i=0;i<n;i++){
            // cout<<arr[i].profit<<" ";
            if(arr[i].dead>maxM){
                maxM=arr[i].dead;
                
            }
            
        }
        // cout<<"\n";
        
        bool *visited=new bool[maxM];
        for(int i=0;i<maxM;i++){
            visited[i]=false;
        }
        int count=0;
        int profit=0;
        for(int i=0;i<n;i++){
            if(visited[arr[i].dead-1]==false){
                count+=1;
                profit+=arr[i].profit;
                visited[arr[i].dead-1]=true;
            }else{
                for(int j=(arr[i].dead-2);j>=0;j--){
                    if(visited[j]==false){
                        count+=1;
                        profit+=arr[i].profit;
                        visited[j]=true;
                        break;
                        
                    }
                }
            }
            // cout<<profit<<endl;
            
            
        }
        vector<int>v;
        v.push_back(count);
        v.push_back(profit);
        return v;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends