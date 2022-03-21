

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.

f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.

this is tricky problem completely uses mathematics concepts


*/

int maxArr(vector<int> &A)
{
    int max_1 = INT_MIN;
    int max_2 = INT_MIN;
    int min_1 = INT_MAX;
    int min_2 = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        max_1 = max(max_1, A[i] + i);
        max_2 = max(max_2, -A[i] + i);
        min_1 = min(min_1, A[i] + i);
        min_2 = min(min_2, -A[i] + i);
    }

    return max((max_1 - min_1), (max_2 - min_2));
}
