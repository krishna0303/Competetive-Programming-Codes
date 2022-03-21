
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    queue<pair<int, int>> q;
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            if (A[i][j] == 1)
            {
                count += 1;
            }
            if (A[i][j] == 0)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        bool flag = false;
        for (int x = 0; x < A[0].size(); x++)
        {
            if (A[i][x] == 1)
            {
                count -= 1;
                A[i][x] = 0;
                if (count == 0)
                {
                    flag = true;
                    break;
                }
            }
        }
        for (int x = 0; x < A.size(); x++)
        {
            if (A[x][j] == 1)
            {
                count -= 1;
                A[x][j] = 0;
                if (count == 0)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
        {
            break;
        }
    }
}
