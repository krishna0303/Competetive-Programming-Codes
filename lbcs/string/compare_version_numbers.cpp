

#include <bits/stdc++.h>
using namespace std;

/*
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

*/

int compareVersion(string A, string B)
{
    int i = 0, j = 0;

    while (i < A.length() && j < A.length())
    {
        string x = "";
        string y = "";

        while (i < A.length() && A[i] == '0')
        {
            i++;
        }

        while (i < A.length() && A[i] != '.')
        {
            x += A[i];
            i++;
        }

        while (j < B.length() && B[j] == '0')
        {
            j++;
        }

        while (j < B.length() && B[j] != '.')
        {
            y += B[j];
            j++;
        }

        if (x != y)
        {
            if (x.length() == y.length())
                return x.compare(y) > 0 ? 1 : -1;
            return x.length() > y.length() ? 1 : -1;
        }

        i++;
        j++;
    }

    while (i < A.length() && A[i] == '0')
    {
        i++;
    }

    while (j < B.length() && B[j] == '0')
    {
        j++;
    }

    if (i >= A.length() && j >= B.length())
        return 0;

    return i > j ? 1 : -1;
}