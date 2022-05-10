
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

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int lefts[n];
    int rights[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && (heights[st.top()] >= heights[i]))
        {
            st.pop();
        }
        if (st.empty())
        {
            lefts[i] = 0;
        }
        else
        {
            lefts[i] = st.top() + 1;
        }
        st.push(i);
    }

    // clear stack
    while (!st.empty())
    {
        st.pop();
    }
    // for right smaller elements
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && (heights[st.top()] >= heights[i]))
        {
            st.pop();
        }
        if (st.empty())
        {
            rights[i] = n - 1;
        }
        else
        {
            rights[i] = st.top() - 1;
        }
        st.push(i);
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (rights[i] - lefts[i] + 1));
    }
    return ans;
}
