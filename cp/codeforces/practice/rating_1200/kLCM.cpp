#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 0)
        {
            int val = n / 2;
            if (val % 2 == 0)
            {
                cout << val << " " << val / 2 << " " << val / 2 << endl;
            }
            else
            {
                cout << val - 1 << " " << val - 1 << " " << 2 << endl;
            }
        }
        else
        {

            cout << 1 << " " << n / 2 << " " << n / 2 << endl;
        }
    }
    return 0;
}