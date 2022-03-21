#include <bits/stdc++.h>
using namespace std;

bool isValid(int n)
{
    if (n % 10 == 3)
    {
        return false;
    }
    int sum = 0;
    while (n != 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    if (sum % 3 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int diff = abs(a - b);
        int ans = -1;
        if ((2 * diff) < a || (2 * diff) < b || (2 * diff) < c)
        {
            ans = -1;
        }
        else if (c > diff)
        {
            ans = c - diff;
        }
        else
        {
            ans = c + diff;
        }
        cout << ans << endl;
    }
    return 0;
}