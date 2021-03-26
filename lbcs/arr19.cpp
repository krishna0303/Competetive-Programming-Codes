#include<bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


//this is my solution

bool compare(vector<int>&a,vector<int>&b){
    if(a[0]!=b[0]){
        return a[0]<b[0];

    }
    return a[1]<b[1];
        

}

class Solution {
public:
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
    //     for(int i=0;i<intervals.size();i++){
    //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    // }
        vector<vector<int>>ans;
         
       
        int start=intervals[0][0];
            int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            
            
            if(end>=intervals[i][0]){
                start=min(start,intervals[i][0]);
                end=max(intervals[i][1],end);
                
            }else{
                ans.push_back(vector<int>({start,end}));
                start=intervals[i][0];
                end=intervals[i][1];
            }
            
            
            
           

        }
        
        
                ans.push_back(vector<int>({start,end}));
        
        return ans;
        
    }
};


// bool cmp(vector<int> &a, vector<int> &b)
// {
//     if (a[0] != b[0])
//     {
//         return a[0] < b[0];
//     }
//     return a[1] < b[1];
// }

// class Solution
// {
// public:
//     vector<vector<int>> merge(vector<vector<int>> &intervals)
//     {

//         sort(intervals.begin(), intervals.end(), cmp);

//         vector<vector<int>> ans;

//         int initialSize = intervals.size();
//         int leftEndValue = intervals[0][0];
//         int rightEndValue = intervals[0][1];

//         for (int i = 1; i < intervals.size(); i++)
//         {

//             if (rightEndValue >= intervals[i][0])
//             {
//                 leftEndValue = min(leftEndValue, intervals[i][0]);
//                 rightEndValue = max(rightEndValue, intervals[i][1]);
//             }
//             else
//             {
//                 ans.push_back(vector<int>({leftEndValue, rightEndValue}));
//                 leftEndValue = intervals[i][0];
//                 rightEndValue = intervals[i][1];
//             }
//         }

//         ans.push_back(vector<int>({leftEndValue, rightEndValue}));

//         return ans;
//     }

//     vector<vector<int>> mergeOld(vector<vector<int>> &intervals)
//     {

//         sort(intervals.begin(), intervals.end(), cmp);

//         int s = 0, r = 1;
//         vector<vector<int>> ans;

//         int initialSize = intervals.size();
//         int leftEndValue = intervals[s][0];
//         int rightEndValue = intervals[s][1];

//         while (s + r < initialSize)
//         {
//             int e = s + r;
//             if (rightEndValue >= intervals[e][0])
//             {
//                 leftEndValue = min(leftEndValue, intervals[e][0]);
//                 rightEndValue = max(rightEndValue, intervals[e][1]);
//                 r += 1;
//             }
//             else
//             {
//                 ans.push_back(vector<int>({leftEndValue, rightEndValue}));
//                 s = e;
//                 r = 1;
//                 leftEndValue = intervals[s][0];
//                 rightEndValue = intervals[s][1];
//             }
//         }

//         // The last one is not going to be added in the loop
//         // so we are handling it here
//         int e = s + r;
//         leftEndValue = min(intervals[e - 1][0], leftEndValue);
//         rightEndValue = max(intervals[e - 1][1], rightEndValue);
//         ans.push_back(vector<int>({leftEndValue, rightEndValue}));

//         return ans;
//     }
// };

// void printVectorOfVector(vector<vector<int>> &intervals)
// {
//     cout << "[";

//     for (int i = 0; i < intervals.size(); i++)
//     {
//         vector<int> &a = intervals[i];
//         if (i < intervals.size() - 1)
//         {
//             cout << "[" << a[0] << ", " << a[1] << "], ";
//         }
//         else
//         {
//             cout << "[" << a[0] << ", " << a[1] << "]";
//         }
//     }

//     cout << "]\n";
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;

//         cin >> n;

//         vector<vector<int>> intervals(n, vector<int>(2));

//         for (int i = 0; i < n; i++)
//         {
//             cin >> intervals[i][0] >> intervals[i][1];
//         }

//         Solution ob;
//         ob.merge(intervals);

//         printVectorOfVector(intervals);
//     }
//     return 0;
// }

// bool compare(vector<int>&a,vector<int>&b){
//     if(a[1]!=b[1]){
//         return a[1]<b[1];

//     }
//     return a[0]<b[0];
        

// }
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end(),compare);
//     //     for(int i=0;i<intervals.size();i++){
//     //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
//     // }
//         vector<vector<int>>ans;
         
//         int start,end;
//         start=intervals[0][0];
//             end=intervals[1][1];
//         for(int i=1;i<intervals.size();i++){
//             vector<int>smallans;
            
//             if(end>=intervals[i][0]){
//                 end=intervals[i][1];
                
//             }else{
//                 smallans.push_back(start);
//                 smallans.push_back(end);
//                 ans.push_back(smallans);
//                 start=intervals[i][0];
//                 end=intervals[i][1];
//             }
            
            
            
           

//         }
//         vector<int>smallans;
//         smallans.push_back(start);
//                 smallans.push_back(end);
//                 ans.push_back(smallans);
        
//         return ans;
        
//     }
int main(){

    vector<vector<int>>v={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>ans=merge(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }


    return 0;
}