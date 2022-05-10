

#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given a number A in a form of string.

You have to find the smallest number that has same set of digits as A and is greater than A.

If A is the greatest possible number with its set of digits, then return -1.



Problem Constraints
 1 <= A <= 10100000

 A doesn't contain leading zeroes.



Input Format
First and only argument is an numeric string denoting the number A.



Output Format
Return a string denoting the smallest number greater than A with same set of digits , if A is the largest possible then return -1.



Example Input
Input 1:

 A = "218765"
Input 2:

 A = "4321"


Example Output
Output 1:

 "251678"
Output 2:

 "-1"

*/

// it  is same questions as next permutations

string solve(string A)
{
    int index = -1;
    for (int i = A.length() - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        return "-1";
    }
    else
    {
        for (int i = A.length() - 1; i >= 0; i--)
        {
            if (A[i] > A[index])
            {
                swap(A[i], A[index]);
                break;
            }
        }
        reverse(A.begin() + index + 1, A.end());
        return A;
    }
}
