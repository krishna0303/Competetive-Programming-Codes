
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solution(string s)
{
    vector<ll> v;
    ll n = s.length();
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            count += 1;
        }
        else
        {
            v.push_back(count);
            count = 0;
        }
    }
    v.push_back(count);
    sort(v.begin(), v.end(), greater<int>());
    ll val = v[0];
    // cout << v[0] << " " << v[1] << endl;
    int val1 = v[1];
    if (val1 == val)
    {
        return "B";
    }
    else
    {
        if (val % 2 != 0)
        {
            return "A";
        }
        else
        {
            return "B";
        }
    }
}

/*  Do not edit below code */
int main()
{
    string n;
    cin >> n;
    string answer = solution(n);
    cout << answer << endl;
}
