

#include <bits/stdc++.h>
using namespace std;

/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"
 */

string fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
    {
        return "0";
    }
    if (denominator == 0)
    {
        return "";
    }
    string result = "";
    // std::cout << numerator << " " << denominator << endl;
    if ((numerator < 0) ^ (denominator < 0))
    {
        // std::cout << "True" << endl;
        result += "-";
    }
    // numerator = abs(numerator);
    // denominator = abs(denominator);
    long num = numerator, den = denominator;
    num = abs(num);
    den = abs(den);
    long res = num / den;
    result += to_string(res);

    long rem = (num % den) * 10;
    if (rem == 0)
    {
        return result;
    }

    std::map<long, int> mp;
    result += ".";
    while (rem != 0)
    {
        if (mp.find(rem) != mp.end())
        {
            int beg = mp[rem];
            string part1 = result.substr(0, beg);
            string part2 = result.substr(beg, result.length() - beg);
            result = part1 + "(" + part2 + ")";
            return result;
        }
        mp[rem] = result.length();
        res = rem / den;
        result += to_string(res);
        rem = (rem % den) * 10;
    }
    return result;
}