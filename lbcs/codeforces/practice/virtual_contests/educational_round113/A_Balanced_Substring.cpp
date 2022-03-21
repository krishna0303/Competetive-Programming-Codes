// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--){

//     }
//     return 0;
// }

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
        string s;
        cin >> s;
        int cnt1 = 0, cnt2 = 0;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                cnt1 += 1;
            }
            else
            {
                cnt2 += 1;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == 'a')
                {
                    cnt1 += 1;
                }
                else
                {
                    cnt2 += 1;
                }
                if (cnt1 == cnt2)
                {
                    cout << i + 1 << " " << j + 1 << endl;
                    flag = true;
                    break;
                }
            }
            cnt1=0;
            cnt2=0;
            if (flag)
            {
                break;
            }
        }
        if (!flag)
        {
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}
