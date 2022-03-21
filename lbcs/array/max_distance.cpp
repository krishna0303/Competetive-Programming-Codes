
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;



Example Input
Input 1:

 A = [3, 5, 4, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Maximum value occurs for pair (3, 4).


*/

int maximumGap(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        left[i] = min(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    int x = 0, y = 0, ans = 0;
    while (x < n && y < n)
    {
        if (right[y] >= left[x])
        {
            ans = max(ans, y - x);
            y++;
        }
        else
        {
            x++;
        }
    }
    return ans;
}
