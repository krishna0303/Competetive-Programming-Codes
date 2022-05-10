
#include <bits/stdc++.h>
using namespace std;

/*

Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.



Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]


this is best approach its time complexity is O(N) SC-O(1)
for better undersdtanding of this approach watch https://www.youtube.com/watch?v=io3N5YTFbxM



*/

class Solution
{
public:
    void insert(vector<int> &arr, int i, int j)
    {
        if (j < arr.size())
        {
            arr[j] = arr[i];
        }
    }
    void duplicateZeros(vector<int> &arr)
    {
        int zeroCount = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                zeroCount += 1;
            }
        }
        int i = arr.size() - 1, j = arr.size() + zeroCount - 1;
        while (i != j)
        {
            insert(arr, i, j--);
            if (arr[i] == 0)
            {
                insert(arr, i, j--);
            }
            i--;
        }
    }
};