#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.

*/

int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int tab[n + 1][sum + 1];
    // Initializing the first value of matrix
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            // if the value is greater than the sum
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    }

    return tab[n][sum];
}

int main()
{
    int n = 4;
    int a[] = {3, 3, 3, 3};
    int sum = 6;

    cout << (subsetSum(a, n, sum));
}
