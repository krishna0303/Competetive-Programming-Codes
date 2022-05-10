#include <bits/stdc++.h>
using namespace std;

/*

10. Regular Expression Matching
Hard

8052

1220

Add to List

Share
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

*/

// brute force approach find all subset and then check if it is valid or not if it is valid then push it into ans stack
//  class Solution
//  {
//  public:
//      int dp[101][101];
//      bool solve(string s, string p, int i, int j)
//      {
//          if (i < 0)
//          {
//              if (j >= 0)
//              {
//                  while (j >= 0)
//                  {
//                      if (p[j] == '*')
//                      {
//                          j -= 2;
//                      }
//                      else
//                      {
//                          return false;
//                      }
//                  }
//                  if (j < 0)
//                  {
//                      return true;
//                  }
//              }
//              else
//              {
//                  return true;
//              }
//          }
//          if (j < 0)
//          {
//              if (i >= 0)
//              {
//                  return false;
//              }
//              else
//              {
//                  return true;
//              }
//          }
//          if (dp[i][j] != -1)
//          {
//              return dp[i][j];
//          }

//         if (s[i] == p[j] || p[j] == '.')
//         {
//             return dp[i][j] = solve(s, p, i - 1, j - 1);
//         }
//         else
//         {
//             if (p[j] == '*')
//             {

//                 if (p[j - 1] == s[i] || p[j - 1] == '.')
//                 {
//                     return dp[i][j] = solve(s, p, i - 1, j) || solve(s, p, i, j - 2);
//                 }
//                 else
//                 {
//                     return dp[i][j] = solve(s, p, i, j - 2);
//                 }
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }

//     bool isMatch(string s, string p)
//     {
//         memset(dp, -1, sizeof(dp));
//         return solve(s, p, s.length(), p.length());
//     }
// };

// Efficient approach only form valid parenthesis

class Solution
{
public:
    vector<string> ans;

    void solve(string &s, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(s);
            return;
        }

        if (open > 0)
        {
            s.push_back('(');
            solve(s, open - 1, close);
            s.pop_back();
        }
        if (close > 0)
        {
            if (open < close)
            {
                s.push_back(')');
                solve(s, open, close - 1);
                s.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        ans.clear();
        string s = "";
        solve(s, n, n);
        return ans;
    }
};
/*

Complexity Analysis:

Time Complexity: O(2^n).
For every index there can be two options ‘{‘ or ‘}’. So it can be said that the upper bound of time complexity is O(2^n) or it has exponential time complexity.
Space Complexity: O(n).
The space complexity can be reduced to O(n) if global variable or static variable is used to store the output string.



*/