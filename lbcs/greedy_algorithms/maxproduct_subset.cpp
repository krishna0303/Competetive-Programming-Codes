#include<bits/stdc++.h>
using namespace std;

/*

If there are even number of negative numbers and no zeros, result is simply product of all
If there are odd number of negative numbers and no zeros, result is product of all except the negative integer with the least absolute value.
If there are zeros, result is product of all except these zeros with one exceptional case. The exceptional case is when there is one negative number and all other elements are 0. In this case, result is 0.

*/

int solve(int*a,int n){
    if (n == 1)
        return a[0];
 
    // Find count of negative numbers, count
    // of zeros, negative number
    // with least absolute value
    // and product of non-zero numbers
    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    for (int i = 0; i < n; i++) {
 
        // If number is 0, we don't
        // multiply it with product.
        if (a[i] == 0) {
            count_zero++;
            continue;
        }
 
        // Count negatives and keep
        // track of negative number
        // with least absolute value
        if (a[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
 
        prod = prod * a[i];
    }
 
    // If there are all zeros
    if (count_zero == n)
        return 0;
 
    // If there are odd number of
    // negative numbers
    if (count_neg & 1) {
 
        // Exceptional case: There is only
        // negative and all other are zeros
        if (count_neg == 1 &&
            count_zero > 0 &&
            count_zero + count_neg == n)
            return 0;
 
        // Otherwise result is product of
        // all non-zeros divided by
        //negative number with
        // least absolute value
        prod = prod / max_neg;
    }
 
    return prod;

 
    

}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    cout<<solve(arr,n)<<endl;
    return 0;
}