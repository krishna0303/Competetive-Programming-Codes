#include <bits/stdc++.h>

using namespace std;
/*

 PROBLEM STATEMENT:

You are given an array and a difference, We need to find how many subsets are there in the array such that the difference between the sum of the two subsets is equal to the given difference. 

QUICK POINTS:

1. Let's take sum1 be the subset of one subset, sum be the total sum of the array and diff be the given difference.

It is obvious that

                    sum1-sum2=diff

                => sum1-(sum-sum1)=diff

                => 2*sum1= diff+ sum

                => sum1= (diff+sum)/2;

So, simply we can get the answer by finding the number of subsets with given sum= sum1, which is same as subset sum problem.


*/

int main()

{

    int n, diff;

    cin >> n >> diff;

    int a[n];

    for (int i = 0; i < n; i++)

        cin >> a[i];

    int sum = 0;

    for (int i = 0; i < n; i++)

        sum = sum + a[i];

    int sum1 = (diff + sum) / 2;

    int dp[n + 1][sum1 + 1];

    for (int i = 0; i < n + 1; i++)

    {

        for (int j = 0; j < sum1 + 1; j++)

        {

            if (j == 0)

                dp[i][j] = 1;

            else if (i == 0)

                dp[i][j] = 0;

            else

            {

                if (a[i - 1] <= j)

                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];

                else

                    dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][sum1] << endl;

    return 0;
}

// INPUT :

//     6 1 2 3 4 5 6

//     OUTPUT :

//     5