
#include <bits/stdc++.h>
using namespace std;
/*
Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.



Problem Constraints
1 <= |A| <= 100000


1 <= A[i] <= 1000000000

for better understanding watch striver video



*/

vector<int> slidingMaximum(const vector<int> &A, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < A.size(); i++)
    {
        if (!dq.empty() && (i - k) == dq.front())
        {
            dq.pop_front();
        }
        while (!dq.empty() && A[dq.back()] <= A[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
        {
            ans.push_back(A[dq.front()]);
        }
    }
    return ans;
}
