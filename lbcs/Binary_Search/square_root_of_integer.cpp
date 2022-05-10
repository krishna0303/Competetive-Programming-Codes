
#include <bits/stdc++.h>
using namespace std;

/*

Given an integer A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.

NOTE: Do not use sort function from standard library. Users are expected to solve this in O(log(A)) time.

*/

int sqrt(int A)
{
    if (A == 1)
    {
        return 1;
    }
    int low = 0;
    int high = A / 2;
    int val = 0;
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        if ((mid * mid) == A)
        {
            val = mid;
            break;
        }
        else if ((mid * mid) < A)
        {
            val = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return val;
}
