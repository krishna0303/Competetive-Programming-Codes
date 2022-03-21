#include <bits/stdc++.h>
using namespace std;

/*

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6

Possible with [2, 3]

best explanation ever by codelibrary for this problem

*/

int maxProduct(const vector<int> &A)
{
    int minm = A[0];
    int maxm = A[0];
    int res = A[0];

    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] < 0)
        {
            swap(maxm, minm);
        }
        maxm = max(A[i], A[i] * maxm);
        minm = min(A[i], A[i] * minm);
        res = max(res, maxm);
    }
    return res;
}
