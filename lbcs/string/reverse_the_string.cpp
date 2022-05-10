
#include <bits/stdc++.h>
using namespace std;
/*

Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.

*/

string solve(string s)
{
    int n = s.length();
    // int i=0,j=n-1;
    // string word1="",word2="";
    // while(i<j){

    // }
    string str = "";
    int i = 0;
    string temp = "";
    while (i < n)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
            i++;
        }
        else
        {
            if (temp.length() != 0)
            {
                if (str.length() == 0)
                {
                    str = temp;
                }
                else
                {
                    str = temp + " " + str;
                }
                temp = "";
            }
            i++;
        }
    }
    if (temp.length() != 0)
    {
        if (str.length() == 0)
        {
            str = temp;
        }
        else
        {
            str = temp + " " + str;
        }
    }
    return str;
}
