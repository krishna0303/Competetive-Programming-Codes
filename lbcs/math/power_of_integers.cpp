

#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True
as 2^2 = 4.

*/

int isPower(int A)
{
    for (int i = 1; i <= sqrt(A); i++)
    {
        int p = log(A) / log(i);
        if (pow(i, p) == A)
        {
            return 1;
        }
    }
    return 0;
}
