#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

*/

// class Solution
// {
// public:
//     int maxProfit(int k, vector<int> &prices)
//     {
//         vector<int> mn(k + 1, INT_MAX);
//         vector<int> profit(k + 1, 0);
//         for (auto n : prices)
//         {
//             for (int i = 1; i < k + 1; i++)
//             {
//                 mn[i] = min(mn[i], n - profit[i - 1]);
//                 profit[i] = max(profit[i], n - mn[i]);
//             }
//         }
//         return profit[k];
//     }
// };

map<string, int> dp;
int solve(const vector<int> &A, int i, int count, bool flag)
{
    if (i == A.size())
    {
        return 0;
    }
    if (count == 2)
    {
        return 0;
    }
    string str = to_string(i) + to_string(count) + to_string(flag);
    if (dp.find(str) != dp.end())
    {
        return dp[str];
    }

    if (!flag)
    {

        return dp[str] = max(solve(A, i + 1, count, true) - A[i], solve(A, i + 1, count, flag));
    }
    else
    {
        return dp[str] = max(solve(A, i + 1, count + 1, false) + A[i], solve(A, i + 1, count, true));
    }
}

int maxProfit(const vector<int> &A)
{
    if (A.size() <= 1)
    {
        return 0;
    }
    dp.clear();
    return solve(A, 0, 0, false);
}