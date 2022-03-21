

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

this is my solution .
dry run on
DDIDIIDD this string to better understand the approach


*/

vector<int> findPerm(const string A, int n)
{
    vector<int> ans;
    int countD = 0, countI = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 'D')
        {
            countD += 1;
        }
        else
        {
            countI += 1;
        }
    }
    if (A[0] == 'I')
    {
        ans.push_back(1);
    }
    if (A[0] == 'D')
    {
        ans.push_back(countD + 1);
    }
    int x = countD;
    int y = n - countI + 1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 'D')
        {
            ans.push_back(x);
            x--;
        }
        else
        {
            ans.push_back(y);
            y++;
        }
    }
    return ans;
}
