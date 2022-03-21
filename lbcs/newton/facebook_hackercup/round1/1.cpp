#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("weak_typing_chapter_1_input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("A1_chapter1_output.txt", "w", stdout);

#endif
    int t;
    cin >> t;
    int k = 1;
    while (k <= t)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count1 = 0, count2 = 0;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (!flag)
            {
                if (s[i] == 'X')
                {
                    count1 += 1;
                    flag = true;
                }
            }
            else
            {
                if (s[i] == 'O')
                {
                    count1 += 1;
                    flag = false;
                }
            }
        }
        flag = false;
        for (int i = 0; i < n; i++)
        {
            if (!flag)
            {
                if (s[i] == 'O')
                {
                    count2 += 1;
                    flag = true;
                }
            }
            else
            {
                if (s[i] == 'X')
                {
                    count2 += 1;
                    flag = false;
                }
            }
        }
        cout << "Case #" << k << ": " << min(count1, count2) << endl;
        k++;
    }
    return 0;
}