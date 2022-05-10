

#include <bits/stdc++.h>
using namespace std;

/*

Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.




Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.
Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17 ``` Matrix=

*/
int countSmaller(vector<vector<int>> &A, int i, int target)
{
    int low = 0;
    int high = A[0].size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[i][mid] <= target)
        {

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int findMedian(vector<vector<int>> &A)
{
    int minm = INT_MAX, maxm = INT_MIN;
    int n = A.size();
    int m = A[0].size();
    for (int i = 0; i < n; i++)
    {
        minm = min(minm, A[i][0]);
        maxm = max(maxm, A[i][m - 1]);
    }
    int desired = (n * m + 1) / 2;
    while (minm < maxm)
    {
        int mid = minm + (maxm - minm) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            //    count+=upper_bound(A[i].begin(), A[i].begin()+m, mid) -A[i].begin();
            count += countSmaller(A, i, mid);
        }
        if (count < desired)
        {
            minm = mid + 1;
        }
        else
        {
            maxm = mid;
        }
    }
    return minm;
}
