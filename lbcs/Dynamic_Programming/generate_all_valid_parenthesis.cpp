

#include <bits/stdc++.h>
using namespace std;

/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

*/

class Solution
{
public:
    bool isValid(string s)
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
                if (st.empty() || st.top() == ')')
                {
                    st.push(s[i]);
                }
                else
                {

                    st.pop();
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }

    void solve(int i, int n, vector<string> &ans, string str)
    {
        if (i > n)
        {
            return;
        }
        // cout<<i<<endl;
        if (i == n)
        {
            if (isValid(str))
            {
                ans.push_back(str);
                return;
            }
            else
            {
                return;
            }
        }
        solve(i + 1, n, ans, str + '(');
        solve(i + 1, n, ans, str + ')');
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        solve(0, 2 * n, ans, "");
        return ans;
    }
};