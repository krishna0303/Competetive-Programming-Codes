

#include <bits/stdc++.h>
using namespace std;
/*

Problem Description



 You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position.
Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.



Problem Constraints
1 <= secret.length, guess.length <= 100000
secret.length == guess.length
secret and guess consist of digits only.

*/

/*

my working solution
string Solution::solve(string A, string B) {
    unordered_map<char,int>m;
    for(int i=0;i<A.length();i++){
        m[A[i]]++;
    }
    int bullCount=0,couwCount=0;
    for(int i=0;i<A.length();i++){
        if(A[i]==B[i]){

            bullCount+=1;
            m[A[i]]--;
        }
    }
    for(int i=0;i<B.length();i++){

        if(A[i]!=B[i]&&m.find(B[i])!=m.end()&&(m[B[i]]>0)){
               couwCount+=1;
                m[B[i]]--;


        }

    }
    return to_string(bullCount)+"A"+to_string(couwCount)+"B";
}



*/

string solve(string secret, string guess)
{
    int n = guess.length();

    int bulls = 0, cows = 0;
    int sec[10] = {0}, gue[10] = {0};

    for (int i = 0; i < n; i++)
    {
        if (secret[i] == guess[i])
        {
            bulls++;
        }
        else
        {
            sec[(secret[i] - '0')]++;
            gue[(guess[i] - '0')]++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cows += min(sec[i], gue[i]);
    }

    string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';

    return ans;
}