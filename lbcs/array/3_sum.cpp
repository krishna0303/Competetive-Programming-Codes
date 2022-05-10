
#include <bits/stdc++.h>
using namespace std;

/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.

Return the sum of the three integers.

Assume that there will only be one solution

Example:

given array S = {-1 2 1 -4},

and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/

int threeSumClosest(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int ans = 0;
    int minm = INT_MAX;
    for (int i = 0; i < A.size() - 2; i++)
    {
        int j = i + 1, k = A.size() - 1;
        bool flag = false;

        while (j < k)
        {

            if (((A[i] + A[j] + A[k]) - B) < minm)
            {
                //  cout<<A[i]+A[j]+A[k]<<" "<<abs(abs(A[i]+A[j]+A[k])-B)<<" "<<minm<<endl;
                ans = A[i] + A[j] + A[k];
                minm = abs((A[i] + A[j] + A[k]) - B);
            }
            // cout<<A[i]+A[j]+A[k]<<endl;
            if ((A[i] + A[j] + A[k]) == B)
            {
                ans = B;
                flag = true;
                break;
            }
            else if ((A[i] + A[j] + A[k]) > B)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return ans;
}
