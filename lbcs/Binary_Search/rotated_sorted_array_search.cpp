
#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers A of size N and an integer B.

array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value B to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return index of B in array A, otherwise return -1
Constraints

1 <= N <= 1000000
1 <= A[i] <= 10^9
all elements in A are disitinct.
For Example

Input 1:
    A = [4, 5, 6, 7, 0, 1, 2, 3]
    B = 4
Output 1:
    0
Explanation 1:
 Target 4 is found at index 0 in A.


Input 2:
    A = [5, 17, 100, 3]
    B = 6
Output 2:
    -1

*/

int bs(const vector<int> &A, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == target)
        {
            return mid;
        }
        else if (A[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int search(const vector<int> &A, int B)
{
    int index = -1;
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            index = i + 1;
            break;
        }
    }
    if (index == -1)
    {
        return bs(A, 0, A.size(), B);
    }
    else
    {
        int val1 = bs(A, 0, index - 1, B);
        int val2 = bs(A, index, A.size(), B);
        if (val1 != -1)
        {
            return val1;
        }
        else if (val2 != -1)
        {
            return val2;
        }
        else
        {
            return -1;
        }
    }
}
