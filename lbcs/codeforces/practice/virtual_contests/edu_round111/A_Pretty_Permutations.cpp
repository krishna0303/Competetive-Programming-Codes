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
        vector<int> ans;
        if (n % 2 == 0)
        {
            int i = 2;
            while (i <= n)
            {
                ans.push_back(i);
                ans.push_back(i - 1);
                i += 2;
            }
            for (int j = 0; j < ans.size(); j++)
            {
                cout << ans[j] << " ";
            }
            cout << endl;
        }
        else
        {
            int i = 2;
            while (i <= n)
            {
                ans.push_back(i);
                ans.push_back(i - 1);
                i += 2;
            }
            i -= 1;
            for (int j = 0; j < ans.size() - 1; j++)
            {
                cout << ans[j] << " ";
            }
            cout << i << " " << ans[ans.size() - 1] << endl;
        }
    }
    return 0;
}