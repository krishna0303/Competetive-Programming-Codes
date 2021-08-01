#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        string s;
        cin >> n >> a >> b;
        cin >> s;
        // int squareRoot = ;
        int ans = 0;
        if (b == 0&&a!=0)
        {
            if (a > 0)
            {
                ans = (n * a);
            }
            else if (a < 0)
            {
                ans = -(n * a);
            }
        }
        else if (a == 0&&b!=0)
        {
            if (b > 0)
            {
                ans = (n * b);
            }
            else if (b < 0)
            {
                ans = -(n * b);
            }
        }
        else if (a < 0 && b > 0)
        {
            ans = (n * a) + (n * b);
        }
        else if (b < 0 && a > 0)
        {
            int count = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] == '1' && s[i + 1] == '0')
                {
                    count += 1;
                }
            }
            ans = (n * a) + (count * b);
        }
        else if(a==0&&b==0){
            ans=0;
        }else{
            
        }
    }
    return 0;
}