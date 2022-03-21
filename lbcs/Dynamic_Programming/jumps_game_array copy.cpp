#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given an array A with non negative numbers, divide the array into two parts such that the average of both the parts is equal.

Return both parts (If exist). If there is no solution. return an empty list.

NOTE:

If a solution exists, you should return a list of exactly 2 lists of integers A and B which follow the following condition :
numElements in A <= numElements in B
If numElements in A = numElements in B, then A is lexicographically smaller than B ( https://en.wikipedia.org/wiki/Lexicographical_order )
If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest.

Array will contain only non negative numbers.



**Input Format**
First andonly argument is an integer array A.



**Output Format**
Return 2D array consisting of two rows where each row denoted a partition.



**Example Input**
Input 1:

 A = [1 7 15 29 11 9]


Example Output
Output 1:

 [9 15] [1 7 11 29]


Example Explanation
Explanation 1:

 The average of part is (15+9)/2 = 12, average of second part elements is (1 + 7 + 11 + 29) / 4 = 12



*/

// this is my solution
//  map<string, bool> m;

// bool check(vector<int> &arr, int i, int sum, int count, vector<int> &res)
// {
//     if (count == 0)
//     {
//         return sum == 0;
//     }
//     if (i >= arr.size())
//     {
//         return false;
//     }
//     string key = to_string(i) + to_string(sum) + to_string(count);
//     if (m.find(key) != m.end())
//     {
//         return m[key];
//     }
//     if (arr[i] <= sum)
//     {
//         res.push_back(arr[i]);
//         if (check(arr, i + 1, sum - arr[i], count - 1, res))
//         {
//             return m[key] = true;
//         }
//         res.pop_back();
//     }
//     if (check(arr, i + 1, sum, count, res))
//     {
//         return m[key] = true;
//     }
//     return m[key] = false;
// }
// vector<vector<int>> avgset(vector<int> &A)
// {
//     int n = A.size();
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += A[i];
//     }
//     vector<vector<int>> ans;
//     vector<int> res;
//     bool flag = false;
//     for (int i = 1; i < n; i++)
//     {
//         if ((sum * i) % n == 0)
//         {
//             int s1 = (sum * i);
//             s1 /= n;
//             if (check(A, 0, s1, i, res))
//             {
//                 flag = true;
//                 break;
//             }
//             res.clear();
//         }
//     }
//     if (flag)
//     {
//         vector<int> temp;
//         multiset<int> st;
//         for (int i = 0; i < res.size(); i++)
//         {
//             st.insert(res[i]);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (st.find(A[i]) == st.end())
//             {
//                 temp.push_back(A[i]);
//             }
//         }
//         sort(res.begin(), res.end());
//         sort(temp.begin(), temp.end());
//         if (res.size() < temp.size())
//         {
//             ans.push_back(res);
//             ans.push_back(temp);
//         }
//         else if (res.size() > temp.size())
//         {
//             ans.push_back(temp);
//             ans.push_back(res);
//         }
//         else
//         {
//             int i = 0;
//             while (i < res.size())
//             {
//                 if (res[i] < temp[i])
//                 {
//                     ans.push_back(res);
//                     ans.push_back(temp);
//                 }
//                 else if (res[i] > temp[i])
//                 {
//                     ans.push_back(temp);
//                     ans.push_back(res);
//                 }
//                 else
//                 {
//                     i++;
//                 }
//             }
//         }

//         res.clear();
//         temp.clear();
//         st.clear();
//     }

//     return ans;
// }

vector<vector<vector<bool>>> dp;
vector<int> arr;
vector<int> res;
int n;

bool possible(int idx, int cur_size, int cur_sum)
{
    if (cur_size == 0)
        return (cur_sum == 0);
    if (idx == n)
        return false;

    if (dp[idx][cur_size][cur_sum] == false)
        return false;
    if (cur_sum >= arr[idx])
    {
        res.push_back(arr[idx]);
        if (possible(idx + 1, cur_size - 1, cur_sum - arr[idx]))
            return true;
        res.pop_back();
    }
    if (possible(idx + 1, cur_size, cur_sum))
        return true;
    return dp[idx][cur_size][cur_sum] = false;
}
vector<vector<int>> avgset(vector<int> &A)
{

    arr.clear();
    res.clear();
    dp.clear();

    arr = A;
    int sum = 0;
    n = A.size();
    for (int i = 0; i < n; i++)
        sum += A[i];
    dp.resize(n, vector<vector<bool>>(n, vector<bool>(sum + 1, true)));

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 1; i <= n / 2; i++)
    {
        if (sum * i % n == 0)
        {
            int cur_sum = (sum * i) / n;
            if (possible(0, i, cur_sum))
            {
                vector<int> res2;
                int p1 = 0, p2 = 0;
                while (p2 < n || p1 < i)
                {
                    if (p1 < i && res[p1] == arr[p2])
                    {
                        p1++;
                        p2++;
                    }
                    else
                    {
                        res2.push_back(arr[p2]);
                        p2++;
                    }
                }
                ans.push_back(res);
                ans.push_back(res2);
                return ans;
            }
        }
    }
    return ans;
}
