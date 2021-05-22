
#include <bits/stdc++.h>
#define ll long long int
using namespace std;


ll BinaryExpo(ll x1, ll y1, ll p1)
{
	ll result = 1; 

	x1 = x1 % p1;

	while (y1 > 0) {
	
	
		if (y1 & 1)
			result = (result * x1) % p1;

	
		y1 = y1 >> 1; // y = y/2
		x1 = (x1 * x1) % p1;
	}
	return result%p1;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
       ll a = 2;

	
    ll num;
    cin>>num;
	

	
	ll MOD = 1000000007;

	

	cout << BinaryExpo(a, num-1, MOD) << endl;
    }
	
	return 0;
}