

#include <bits/stdc++.h>
using namespace std;

/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])
 */

int maxPoints(vector<int> &X, vector<int> &Y)
{

    int n = X.size();
    if (n <= 2)
        return n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        map<double, int> cach;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            double slope = 1000000000;
            if (X[j] - X[i] != 0)
            {
                slope = double(Y[i] - Y[j]) / double(X[i] - X[j]);
            }
            cach[slope]++;
            mx = max(mx, cach[slope] + 1);
        }
    }
    return mx;
}