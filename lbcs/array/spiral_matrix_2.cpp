
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.



Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]


*/
vector<vector<int>> generateMatrix(int A)
{
    int left = 0, right = A - 1, top = 0, bottom = A - 1;
    int num = 1;
    vector<vector<int>> mat(A, vector<int>(A));

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            mat[top][i] = num;
            num++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            mat[i][right] = num;
            num++;
        }
        right--;
        for (int i = right; i >= left; i--)
        {
            mat[bottom][i] = num;
            num++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            mat[i][left] = num;
            num++;
        }
        left++;
    }
    return mat;
}
