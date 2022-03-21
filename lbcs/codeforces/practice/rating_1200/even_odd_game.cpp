#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *arr = new ll[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> even, odd;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                even.push_back(arr[i]);
            }
            else
            {
                odd.push_back(arr[i]);
            }
        }
        sort(even.begin(), even.end(), greater<ll>());
        sort(odd.begin(), odd.end(), greater<ll>());

        int i = 0, j = 0;

        ll max1 = 0, max2 = 0;

        bool flag = true;
        int k = 1;
        while (i < even.size() && j < odd.size())
        {
            if (flag)
            {
                if (even[i] >= odd[j])
                {
                    max1 += even[i];
                    i++;
                }
                else
                {
                    j++;
                }

                flag = false;
            }
            else
            {
                if (odd[j] >= even[i])
                {
                    max2 += odd[j];
                    j++;
                }
                else
                {
                    i++;
                }

                flag = true;
            }
        }
        while (i < even.size())
        {
            if (flag)
            {
                max1 += even[i];
                flag = false;
                i++;
            }
            else
            {
                i++;
                flag = true;
            }
        }
        while (j < odd.size())
        {
            if (flag)
            {
                j++;
                flag = false;
            }
            else
            {
                max2 += odd[j];
                flag = true;
                j++;
            }
        }

        // cout << max1 << " " << max2 << endl;
        if (max1 > max2)
        {
            cout << "Alice" << endl;
        }
        else if (max1 == max2)
        {
            cout << "Tie" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
    return 0;
}