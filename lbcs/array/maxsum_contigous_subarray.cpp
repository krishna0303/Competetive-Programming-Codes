#include <bits/stdc++.h>
using namespace std;


//kadane algorithm which also handle if all eleemnts in array are negative
int maxSubArray(const vector<int> &A)
{

    int maxRes = A[0];
    int res = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        maxRes = max(A[i], maxRes + A[i]);
        if (maxRes > res)
        {
            res = maxRes;
        }
    }
    return res;
}
