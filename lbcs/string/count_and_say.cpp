#include <bits/stdc++.h>
using namespace std;
/*

Problem Description

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11. 11 is read off as two 1s or 21.
21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2, the sequence is 11.

*/

string longestPalindrome(string A)
{
    int strLen = A.length();
    if (strLen == 1)
        return A;

    int i = 0, start, end, maxLen = 0, maxIdx = 0;

    while (i < strLen)
    {
        int start = end = i;
        while (end + 1 < strLen && A[start] == A[end + 1])
            end++;

        i = end + 1;
        while (start - 1 > -1 && end + 1 < strLen && A[start - 1] == A[end + 1])
        {
            start--;
            end++;
        }

        if (end - start + 1 > maxLen)
        {
            maxLen = end - start + 1;
            maxIdx = start;
        }
    }

    return A.substr(maxIdx, maxLen);
}
