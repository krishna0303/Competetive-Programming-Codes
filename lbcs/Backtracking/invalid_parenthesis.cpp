#include <bits/stdc++.h>
using namespace std;
int getMinRemoval(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else if (st.top() == ')')
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.size();
}

void Removal(string s, set<string> &ans, int minimumremoval)
{
    if (minimumremoval == 0)
    {
        int val = getMinRemoval(s);

        if (val == 0)
        {
            ans.insert(s);
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        Removal(left + right, ans, minimumremoval - 1);
    }
}

vector<string> removeInvalidParentheses(string s)
{
    set<string> ans;
    int val = getMinRemoval(s);
    Removal(s, ans, val);

    vector<string> v;
    for (auto it : ans)
    {
        v.push_back(it);
    }
    return v;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = removeInvalidParentheses(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
