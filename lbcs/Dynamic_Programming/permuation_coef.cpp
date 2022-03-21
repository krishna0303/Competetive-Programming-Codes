// A Dynamic Programming based
// solution that uses table P[][]
// to calculate the Permutation
// Coefficient
#include <bits/stdc++.h>

// Returns value of Permutation
// Coefficient P(n, k)

// int permutationCoeff(int n, int k)
// {
// 	int fact[n + 1];

// 	// Base case
// 	fact[0] = 1;

// 	// Calculate value
// 	// factorials up to n
// 	for (int i = 1; i <= n; i++)
// 		fact[i] = i * fact[i - 1];

// 	// P(n,k) = n! / (n - k)!
// 	return fact[n] / fact[n - k];
// }
// TC-O(N)
// SC-O(N)

int permutationCoeff(int n, int k)
{
	int P = 1;

	// Compute n*(n-1)*(n-2)....(n-k+1)
	for (int i = 0; i < k; i++)
		P *= (n - i);

	return P;
}
// TC-O(N)
// SC-O(1)

// Driver Code
int main()
{
	int n = 10, k = 2;
	printf("Value of P(%d, %d) is %d ",
		   n, k, permutationCoeff(n, k));
	return 0;
}
