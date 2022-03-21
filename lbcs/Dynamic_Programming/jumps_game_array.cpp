#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given an array of non-negative integers, A, you are initially positioned at the 0th index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.


// C++ program for Minimum number
// of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x < y) ? x : y; }

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{
    // jumps[n-1] will hold the result
    int* jumps = new int[n];
    int i, j;

    if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;

    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}

// Driver code
int main()
{
    int arr[] = { 1, 3, 6, 1, 0, 9 };
    int size = sizeof(arr) / sizeof(int);
    cout << "Minimum number of jumps to reach end is "
        << minJumps(arr, size);
    return 0;
}

// This is code is contributed by rathbhupendra

*/

// Tc-O(N) SC-O(1)

int canJump(vector<int> &A)
{
    int maxR = A[0];
    int step = A[0];
    int ans = 1;
    if (A.size() <= 1)
    {
        return 1;
    }
    else if (A[0] == 0)
    {
        return 0;
    }
    bool flag = false;
    for (int i = 1; i < A.size(); i++)
    {
        if (i == A.size() - 1)
        {
            return 1;
        }
        maxR = max(maxR, i + A[i]);
        step--;

        if (step == 0)
        {
            if (maxR <= i)
            {
                return 0;
            }
            step = maxR - i;
        }
    }
}