// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--){

//     }
//     return 0;
// }
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
        string s;
        cin >> s;
        char **mat = new char *[n];
        for (int i = 0; i < n; i++)
        {
            mat[i] = new char[n];
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = '#';
            }
        }

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            bool turn = false;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    mat[i][j] = 'X';
                }
                else if (s[i] == '1')
                {
                    if (s[i] == s[j])
                    {
                        if (mat[i][j] == '#')
                        {
                            mat[i][j] = '=';
                            if (mat[j][i] == '#')
                            {
                                mat[j][i] = '=';
                            }
                        }
                    }
                    else
                    {
                        if (mat[i][j] == '#')
                        {
                            mat[i][j] = '+';
                            if (mat[j][i] == '#')
                            {
                                mat[j][i] = '-';
                            }
                        }
                        else
                        {
                            if (mat[i][j] == '-')
                            {
                                flag = true;
                                break;
                            }
                        }
                    }
                }
                else if (s[i] == '2')
                {
                    if (s[j] == '1')
                    {
                        if (mat[i][j] == '#')
                        {
                            mat[i][j] = '-';
                            if (mat[j][i] == '#')
                            {
                                mat[j][i] = '+';
                            }
                        }
                        else
                        {
                            if (mat[i][j] == '+')
                            {
                                flag = true;
                                break;
                            }
                        }
                    }
                    else
                    {
                        if (mat[i][j] == '#' && !turn)
                        {
                            mat[i][j] = '+';
                            if (mat[j][i] == '#')
                            {
                                mat[j][i] = '-';
                            }
                            turn = true;
                        }
                        else if (mat[i][j] == '+' && !turn)
                        {
                            turn = true;
                        }
                        else
                        {
                            if (mat[i][j] == '#' && turn)
                            {
                                mat[i][j] = '-';
                                if (mat[j][i] == '#')
                                {
                                    mat[j][i] = '+';
                                }
                            }
                        }
                    }
                }
            }
            if (s[i] == '2' && !turn)
            {
                flag = true;
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << mat[i][j] << "";
                }
                cout << endl;
            }
        }
    }
    return 0;
}