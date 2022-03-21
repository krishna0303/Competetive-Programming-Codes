#include <bits/stdc++.h>
using namespace std;

char missingChar(string s, string t, bool &flag)
{
    int count = 0;
    char ch;
    for (int i = 0, j = 0; i < s.length() || j < t.length();)
    {
        if (s[i] != t[j])
        {
            count += 1;
            ch = s[i];
            if (count > 1)
            {
                flag = true;
                break;
            }
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    return ch;
}
int main()
{
    int s;
    cin >> s;
    while (s--)
    {
        string t;
        cin >> t;
        int n = t.length();
        int count = 1;
        int sum = 1;
        while (sum <= n)
        {
            sum += count;
            count++;
        }
        count -= 1;
        cout << count << endl;
        string finalAns = t.substr(0, count);
        cout << finalAns << endl;
        string prev = finalAns;
        int i = count;
        int temp = count - 1;
        vector<char> v;
        bool flag = false;

        for (int i = count; i < n;)
        {
            string str = t.substr(i, temp);
            // cout << str << endl;
            char ch = missingChar(prev, str, flag);
            if (flag)
            {
                break;
            }
            v.push_back(ch);
            prev = str;
            i += (temp);
            temp -= 1;
        }
        v.push_back(t[n - 1]);
        if (flag)
        {
            cout << -1 << endl;
        }
        else
        {
            string str1 = "";
            for (int i = 0; i < v.size(); i++)
            {
                str1 += v[i];
            }
            cout << finalAns << " " << str1 << endl;
        }
    }
    return 0;
}