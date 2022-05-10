

#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given an array A containing N integers, find the variance of the array. Return your answer up to 2 decimal points.


Problem Constraints

1 <= N <= 1000 1 <= A[i] <= 1000


Input Format

First argument is an integer, N, denoting the length of the input array Second line consists of N elements, separated by space


Output Format

Return a float value as specified in the question


Example Input

Input 1: N = 10 A = [99, 81, 4, 74, 9, 79, 45, 25, 44, 86]


Example Output

Output 1: 1034.64


Example Explanation

Mean = 54.6, simply apply the formula of variance to get 1034.64


Approach or formula:
Mean is average of element.
Mean of arr[0..n-1] = ∑(arr[i]) / n
where 0 <= i < n
Variance is sum of squared differences from the mean divided by number of elements.
Variance = ∑(arr[i] – mean)2 / n
Standard Deviation is square root of variance
Standard Deviation =  √(variance)

*/

string solve(vector<int> &A)
{
    double mean = 0;
    int n = A.size();
    for (int i = 0; i < A.size(); i++)
    {
        mean += (double)A[i];
    }
    mean /= n;
    // cout<<mean<<endl;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ((A[i] - mean) * (A[i] - mean));
    }
    string ans = to_string(sum / (n));
    int i = 0;
    for (i = 0; i < ans.length(); i++)
    {
        if (ans[i] == '.')
        {
            if (ans[i + 3] >= '5')
            {
                ans[i + 2]++;
                break;
            }
            else
            {
                break;
            }
        }
    }
    return ans.substr(0, i + 3);
}
