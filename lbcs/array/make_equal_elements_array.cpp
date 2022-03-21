

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Given an array of all positive integers and an element “x”.

You need to find out whether all array elements can be made equal or not by performing any of the 3 operations: add x to any element in array, subtract x from any element from array, do nothing.

 This operation can be performed only once on an element of array.

*/

int solve(vector<int> &A, int B)
{
    int val = A[0];
    bool flag = false;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] == val || A[i] + B == val || (A[i] - B) == val)
        {
            continue;
        }
        else
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        val = A[0] + B;
        flag = false;
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] == val || A[i] + B == val || (A[i] - B) == val)
            {
                continue;
            }
            else
            {
                flag = true;
                break;
            }
        }
    }
    if (flag)
    {
        val = A[0] - B;
        flag = false;
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] == val || A[i] + B == val || (A[i] - B) == val)
            {
                continue;
            }
            else
            {
                flag = true;
                break;
            }
        }
    }
    if (!flag)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
