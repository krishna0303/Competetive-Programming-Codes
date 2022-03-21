#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i = 1;
        int sum = 0;
        while (sum < n)
        {
            sum += i;
            i++;
        }
        i--;
        int k = (i * (i + 1)) / 2;
        if (n + 1 == k)
        {
            cout << i + 1 << endl;
        }
        else
        {

            cout << i << endl;
        }
    }
    return 0;
}