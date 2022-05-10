

#include <bits/stdc++.h>
using namespace std;

/*

Problem Description

Given a string A of size N, find and return the longest palindromic substring in A.

Substring of string A is A[i...j] where 0 <= i <= j < len(A)

Palindrome string:

A string which reads the same backwards. More formally, A is palindrome if reverse(A) = A.

Incase of conflict, return the substring which occurs first ( with the least starting index).

*/
// string longestPalindrome(string A)
// {
//     string ans = "";
//     int maxm = INT_MIN;
//     for (int x = 0; x < A.length(); x++)
//     {
//         int i = 0;
//         int j = 0;
//         int count = 0, count2 = 0;
//         string str = "", str2 = "";

//         if (x != 0 && A[x - 1] == A[x])
//         {
//             str2 += A[x - 1];
//             str2 += A[x];
//             i = x - 2;
//             j = x + 1;
//             count2 = 2;
//             while (i >= 0 && j < A.length())
//             {
//                 if (A[i] == A[j])
//                 {
//                     str2 += A[j];
//                     str2 = A[i] + str2;
//                     i--;
//                     j++;
//                     count2 += 2;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             if (str2.length() == 2)
//             {
//                 i = x - 2;
//                 while (i >= 0)
//                 {
//                     if (A[i] == A[x])
//                     {
//                         str2 = A[i] + str2;
//                         count2 += 1;
//                         i--;
//                     }
//                     else
//                     {
//                         break;
//                     }
//                 }
//             }
//         }
//         str += A[x];
//         i = x - 1;
//         j = x + 1;
//         count = 1;
//         while (i >= 0 && j < A.length())
//         {
//             if (A[i] == A[j])
//             {
//                 str += A[j];
//                 str = A[i] + str;
//                 i--;
//                 j++;
//                 count += 2;
//             }
//             else
//             {
//                 break;
//             }
//         }

//         if (count > count2)
//         {
//             if (count > maxm)
//             {
//                 maxm = count;
//                 ans = str;
//             }
//         }
//         else if (count < count2)
//         {
//             if (count2 > maxm)
//             {
//                 maxm = count2;
//                 ans = str2;
//             }
//         }
//     }
//     return ans;
// }

// better approach is to use expand both sides as taking each element as center of palindrome
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
