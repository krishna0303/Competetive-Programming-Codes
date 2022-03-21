#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n, m, maxSum;
    cin >> n >> m >> maxSum;
    ll *arr1 = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    ll *arr2 = new ll[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    ll sum = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            sum += arr1[i];
            if (sum > maxSum)
            {
                break;
            }
            count += 1;
            i++;
        }
        else
        {
            sum += arr2[j];
            if (sum > maxSum)
            {
                break;
            }
            count += 1;
            j++;
        }
    }
    while (i < n)
    {
        sum += arr1[i];
        if (sum > maxSum)
        {
            break;
        }
        count += 1;
        i++;
    }
    while (j < m)
    {
        sum += arr2[j];
        if (sum > maxSum)
        {
            break;
        }
        count += 1;
        j++;
    }
    cout << count << endl;
}