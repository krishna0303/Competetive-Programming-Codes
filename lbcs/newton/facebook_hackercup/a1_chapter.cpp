#include <bits/stdc++.h>
using namespace std;

bool isVowel(char s)
{
    if (s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("consistency_chapter_1_input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output_chapter_1.txt", "w", stdout);

#endif

    int t;
    cin >> t;
    int k = 1;
    while (k <= t)
    {
        string s;
        cin >> s;
        map<char, int> m;

        int vCnt = 0, cCnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]] += 1;
            if (isVowel(s[i]))
            {
                vCnt += 1;
            }
            else
            {
                cCnt += 1;
            }
        }
        int ans = INT_MAX;
        if (m.size() == 1)
        {
            ans = 0;
        }
        else if (vCnt == 0 || cCnt == 0)
        {
            ans = s.length();
        }
        else
        {

            for (int i = 0; i < s.length(); i++)
            {
                int count = 0;
                int j = i - 1;
                while (j >= 0)
                {
                    if (s[j] != s[i])
                    {
                        if (isVowel(s[i]) == isVowel(s[j]))
                        {
                            count += 2;
                        }
                        else
                        {
                            count += 1;
                        }
                    }
                    j--;
                }
                j = i + 1;
                while (j < s.length())
                {
                    if (s[j] != s[i])
                    {
                        if (isVowel(s[i]) == isVowel(s[j]))
                        {
                            count += 2;
                        }
                        else
                        {
                            count += 1;
                        }
                    }
                    j++;
                }
                if (count < ans)
                {
                    ans = count;
                }
            }
        }
        cout << "Case #" << k << ": " << ans << endl;
        k++;
    }
    return 0;
}
