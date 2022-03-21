#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> split_string(string);

void theHackathon(ll n, ll m, ll a, ll b, ll f, ll s, ll t)
{
    // Participant code here
    map<string, ll> m1;
    // map<string, pair<ll, vector<ll>>> m2;
    map<string, ll> m2;
    map<ll, vector<ll>> m3;

    for (int i = 0; i < n; i++)
    {
        string x;
        int y;
        cin >> x >> y;
        m1[x] = y - 1;

        m2[x] = 0;
    }
    int count = 1;
    for (ll i = 0; i < m; i++)
    {
        string x1, x2;
        cin >> x1 >> x2;
        // cout << m2[x1].first << " " << m2[x2].first << endl;
        if (m2[x1] == 0 && m2[x2] == 0)
        {
            m2[x1] = count;
            m2[x2] = count;
            ll par1 = m1[x1];
            ll par2 = m1[x2];
            m3[count] = {0, 0, 0, 0};
            m3[count][par1] += 1;
            m3[count][par2] += 1;
            m3[count][3] += 2;

            count += 1;
        }
        else if ((m2[x1] != 0 && m2[x2] == 0))
        {
            ll groupno = m2[x1];
            if (m3[groupno][3] < b)
            {

                ll par = m1[x2];
                ll temp = 0;
                if (par == 0)
                {
                    temp = f;
                }
                else if (par == 1)
                {
                    temp = s;
                }
                else
                {
                    temp = t;
                }
                if (m3[groupno][par] < temp)
                {
                    m2[x2] = groupno;
                    m3[groupno][par] += 1;
                    m3[groupno][3] += 1;
                }
            }
        }
        else if ((m2[x1] == 0 && m2[x2] != 0))
        {
            // cout << m2[x2].second[3] << " " << b << endl;
            int groupno = m2[x2];
            if (m3[groupno][3] < b)
            {

                ll par = m1[x1];
                // cout << par << endl;
                ll temp = 0;
                if (par == 0)
                {
                    temp = f;
                }
                else if (par == 1)
                {
                    temp = s;
                }
                else
                {
                    temp = t;
                }
                // cout << m2[x2].second[par] << " " << temp << endl;
                if (m3[groupno][par] < temp)
                {
                    m2[x1] = groupno;
                    m3[groupno][par] += 1;
                    m3[groupno][3] += 1;

                    // cout << m2[x1].second[par] << " " << m2[x1].second[3] << endl;
                }
            }
        }
        else
        {
            // cout << m2[x1].first << " " << m2[x2].first << endl;
            if (m2[x1] == m2[x2])
            {
                continue;
            }
            else
            {
                ll groupx1 = m2[x1];
                ll groupx2 = m2[x2];

                // cout << m2[x1].second[3] << " " << m2[x2].second[3] << endl;
                if ((m3[groupx1][3] + m3[groupx2][3]) <= b)
                {
                    ll z1 = m3[groupx1][0] + m3[groupx2][0];
                    ll z2 = m3[groupx1][1] + m3[groupx2][1];
                    ll z3 = m3[groupx1][2] + m3[groupx2][2];
                    ll sum = m3[groupx1][3] + m3[groupx2][3];

                    if (z1 <= f && z2 <= s && z3 <= t)
                    {
                        m3[count] = {z1, z2, z3, sum};
                        for (auto &it : m2)
                        {
                            if (it.second == groupx1 || it.second == groupx2)
                            {
                                it.second = count;
                            }
                        }
                        m3.erase(groupx1);
                        m3.erase(groupx2);
                        count++;
                    }
                }
                // cout << m2[x1].second[3] << " " << m2[x2].second[3] << endl;
            }
        }
    }
    ll maxGroupSize = 0;
    vector<ll> maxGroupNo;
    for (auto it : m3)
    {
        if (it.second[3] > maxGroupSize)
        {
            maxGroupSize = it.second[3];
            // maxGroupNo = it.first;
        }
    }
    for (auto it : m3)
    {
        if (it.second[3] == maxGroupSize)
        {
            maxGroupSize = it.second[3];
            // maxGroupNo = it.first;
            maxGroupNo.push_back(it.first);
        }
    }

    if (maxGroupNo.size() == 0 || maxGroupSize < a)
    {
        cout << "no groups" << endl;
        return;
    }
    vector<string> ans;
    for (int i = 0; i < maxGroupNo.size(); i++)
    {

        for (auto it : m2)
        {
            if (it.second == maxGroupNo[i])
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }
    }

    // cout << endl;
}

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    ll n = stoi(inputdata[0]);

    ll m = stoi(inputdata[1]);

    ll a = stoi(inputdata[2]);

    ll b = stoi(inputdata[3]);

    ll f = stoi(inputdata[4]);

    ll s = stoi(inputdata[5]);

    ll t = stoi(inputdata[6]);

    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y)
                                      { return x == y and x == ' '; });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
