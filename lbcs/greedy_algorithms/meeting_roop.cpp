/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?
 Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
S[] = {1,3,0,5,8,5}
F[] = {2,4,6,7,9,9}
Output: 
4
Explanation:
Four meetings can be held with
given start and end timings.

*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool compare(const pair<int,int>&a,const pair<int,int>&b){
    if(a.second<b.second){
        return true;
    }else if(a.second==b.second){
        return (a.first<b.first);
    }else{
        return false;
    }
}

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.


    //Algorithm

    /*
    first of all sort the value on the basis of end time and then start selecting of number whose start index is greaterr than end time of previous considered value
    */
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back(make_pair(start[i],end[i]));
        }
        sort(v.begin(),v.end(),compare);
        int count=1;
        int endVal=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>endVal){
                endVal=v[i].second;
                count+=1;
            }
            
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends