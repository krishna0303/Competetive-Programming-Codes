
#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
watch rachit jain video for better understanding
*/

int firstMissingPositive(vector<int> &A)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        //A[i] != A[A[i] - 1] this condition is used here to check whether there is repeated number and one number is already in correct position
        //to better understand dry run this [1,1,1] array
        while (A[i] >= 1 && A[i] <= n && A[i] != A[A[i] - 1])
        {
            swap(A[i], A[A[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {

        if (i != A[i] - 1)
        {
            return i + 1;
        }
    }
    return n + 1;
}
