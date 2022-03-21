// { Driver Code Starts
// Initial Template for C++
/*
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.



Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates
to true in 4 ways ((T|T)&(F^T)),
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int mod = 1003;
    unordered_map<string, int> mp;
    int solve(string s, int i, int j, bool isTrue)
    {
        // base condition
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue == true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        // checking in hashmap
        string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        if (mp.find(temp) != mp.end())
            return mp[temp];
        // looping
        int ans = 0;
        for (int k = i + 1; k < j; k = k + 2)
        {
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);
            // if operator is |
            if (s[k] == '|')
            {
                if (isTrue == true)
                    ans = ans + lt * rt + lt * rf + lf * rt;
                else
                    ans = ans + lf * rf;
            }
            else if (s[k] == '^')
            {
                if (isTrue == true)
                    ans = ans + lf * rt + lt * rf;
                else
                    ans = ans + lt * rt + lf * rf;
            }
            else if (s[k] == '&')
            {
                if (isTrue == true)
                    ans = ans + lt * rt;
                else
                    ans = ans + lt * rf + lf * rt + lf * rf;
            }
        }
        return mp[temp] = ans % mod;
    }

    int countWays(int N, string S)
    {
        // code here
        mp.clear();
        return solve(S, 0, N - 1, true) % mod;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
} // } Driver Code Ends

/*

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
//my solution
    int mod=1003;
    unordered_map<string,int>m;
    int solve(string s,int n,bool flag){
        if(n==0){
            return true;
        }
        if(n==1){
            if(flag){
                return s[0]=='T';
            }else{
                return s[0]=='F';
            }
        }
        string key=s+" "+to_string(n)+" "+to_string(flag);
        if(m.find(key)!=m.end()){
            return m[key];
        }
        int temp=0;
        for(int k=1;k<n-1;k+=2){
            int lf=solve(s.substr(0,k),k,false);
            int lt=solve(s.substr(0,k),k,true);
            int rf=solve(s.substr(k+1,n),n-k-1,false);
            int rt=solve(s.substr(k+1,n),n-k-1,true);

            if(flag){
                if(s[k]=='&'){

                    temp=temp+(lt*rt);
                }else if(s[k]=='|'){
                    temp=temp+(lf*rt+lt*rf+lt*rt);
                }else if(s[k]=='^'){
                    temp=temp+(lf*rt+lt*rf);
                }

            }else{
                if(s[k]=='&'){

                    temp=temp+(lf*rt+lt*rf+lf*rf);
                }else if(s[k]=='|'){
                    temp=temp+(lf*rf);
                }else if(s[k]=='^'){
                    temp=temp+(lf*rf+lt*rt);
                }

            }

        }
        return m[key]=temp%mod;

    }
    int countWays(int N, string S){
        // code here

        return solve(S,N,true)%mod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends


*/