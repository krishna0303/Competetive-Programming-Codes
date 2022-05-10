#include <bits/stdc++.h>
using namespace std;
/*

Find if Given number is power of 2 or not.

More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

*/

int power(string A)
{
    if (A.length() == 1 && A[0] == '1')
    {
        return 0;
    }
    long long int num = 0;
    for (int i = 0; i < A.length(); i++)
    {
        num = num * 10 + A[i] - '0';
    }
    // cout<<num<<endl;
    return !(num & (num - 1));
}
