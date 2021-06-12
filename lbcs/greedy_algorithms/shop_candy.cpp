// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int K)
    {
        // Write Your Code here
        int temp=n;
        sort(candies,candies+n);
       
        
        int min=0;
        int max=0;
        int i=0,j=n;
        while(j>i){
            min+=candies[i];
            max+=candies[n-1-i];
            i++;
            j-=K;
        }
        
        
        vector<int>ans;
        ans.push_back(min);
        ans.push_back(max);
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends