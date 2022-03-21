#include <bits/stdc++.h>
using namespace std;

/*
Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most 2 transactions.

Return the maximum possible profit.

Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


*/

/*
DP Solution
TC-O(N)
SC-O(N)

int Solution::maxProfit(const vector<int> &A) {
    if(A.size()<=1){
        return 0;
    }
    int n=A.size();
    int dp[n];
    for(int i=0;i<n;i++)dp[i]=0;
    int ma=A[n-1];
    int mi=A[0];
    for(int i=n-2;i>=0;i--){
        if(A[i]>ma)ma=A[i];
        dp[i]=max(dp[i+1],ma-A[i]);
    }
    for(int i=1;i<n;i++){
        if(A[i]<mi)mi=A[i];
        dp[i]=max(dp[i-1],dp[i]+(A[i]-mi));
    }
    return dp[n-1];
}

*/

// TC-O(N)
// SC-O(1)

int maxProfit(const vector<int> &arr)
{
    int first_buy = INT_MIN;
    int first_sell = 0;
    int second_buy = INT_MIN;
    int second_sell = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        first_buy = max(first_buy, -arr[i]); // we set prices to negative, so the calculation of profit will be convenient
        first_sell = max(first_sell, first_buy + arr[i]);
        second_buy = max(second_buy, first_sell - arr[i]); // we can buy the second only after first is sold
        second_sell = max(second_sell, second_buy + arr[i]);
    }
    return second_sell;
}
