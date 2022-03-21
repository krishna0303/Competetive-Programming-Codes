#include <bits/stdc++.h>
using namespace std;
/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
*/

void rotate(vector<vector<int>> &A)
{
    // tell the interviewr basic approach is to use another matrix to store the clockwise rotation of original ,matrix
    // but it takes extra O(N^2) which is not allowed

    // 2nd approach using transpose

    int n = A.size();
    // int m=A[0].size(); since n*n matrix

    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    // reversing each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = A[i][j];
            A[i][j] = A[i][n - j - 1];
            A[i][n - j - 1] = temp;
        }
    }
}
