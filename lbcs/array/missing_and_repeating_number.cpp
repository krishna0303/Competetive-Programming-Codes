#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{
    int xo = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        xo = xo ^ A[i];
    }
    for (int i = 1; i <= A.size(); i++)
    {
        xo = xo ^ i;
    }
    int x = 0;
    int y = 0;
    int bitmask = (xo & (-xo));
    /*
    get rightmost set bit,

    x & -x
    // or
    x & (~x + 1)

    */
    for (int i = 0; i < A.size(); i++)
    {
        if (bitmask & A[i])
        {
            x = x ^ A[i];
        }
        else
        {
            y = y ^ A[i];
        }
    }
    for (int i = 1; i <= A.size(); i++)
    {
        if (bitmask & i)
        {
            x = x ^ i;
        }
        else
        {
            y = y ^ i;
        }
    }
    vector<int> ans;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == x)
        {
            ans.push_back(x);
            ans.push_back(y);
            break;
        }
        else if (A[i] == y)
        {
            ans.push_back(y);
            ans.push_back(x);
            break;
        }
    }
    return ans;
}
