

#include <bits/stdc++.h>
using namespace std;

/*

Given a string A representing a roman numeral.

Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more

details about roman numerals at Roman Numeric System




Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20

*/

int romanToInt(string A)
{
    int intCode[] = {1000, 500, 100, 50, 10, 5, 1};
    char code[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    map<char, int> m;
    for (int i = 0; i < 7; i++)
    {
        m[code[i]] = intCode[i];
    }
    int ans = m[A[A.length() - 1]];
    // cout<<ans<<endl
    for (int i = A.length() - 2; i >= 0; i--)
    {
        if (m[A[i]] < m[A[i + 1]])
        {
            ans -= m[A[i]];
        }
        else
        {
            ans += m[A[i]];
        }
    }
    return ans;
}
