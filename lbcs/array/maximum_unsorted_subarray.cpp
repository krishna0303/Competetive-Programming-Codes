

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.

Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.

If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

*/

vector<int> subUnsort(vector<int> &A)
{
    vector<int> ans;
    int ind1 = -1, ind2 = -1;
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            ind1 = i;
            break;
        }
    }
    if (ind1 == -1)
    {
        ans.push_back(-1);
        return ans;
    }
    for (int i = A.size() - 2; i >= 0; i--)
    {
        if (A[i] > A[i + 1])
        {
            ind2 = i + 1;
            break;
        }
    }
    int minm = INT_MAX;
    int maxm = INT_MIN;
    for (int i = ind1; i <= ind2; i++)
    {
        minm = min(minm, A[i]);
        maxm = max(maxm, A[i]);
    }

    while (ind1 >= 0)
    {
        if (A[ind1] > minm)
        {
            ind1--;
        }
        else
        {
            break;
        }
    }
    ind1 = ind1 + 1;

    while (ind2 < A.size())
    {
        if (A[ind2] < maxm)
        {
            ind2++;
        }
        else
        {
            break;
        }
    }
    ind2 = ind2 - 1;
    ans.push_back(ind1);
    ans.push_back(ind2);
    return ans;
}
