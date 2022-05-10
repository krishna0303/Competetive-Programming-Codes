#include <bits/stdc++.h>
using namespace std;

/*

There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.

For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5

*/
/*

this is brute force approach
double binary_search(vector<int>v,int n,int low,int high){
    if(n%2==0){
        return (double)(v[(n/2)-1]+v[n/2])/2;

    }else{
        return (double)v[n/2];

    }
}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>v;
    int i=0,j=0;
    while(i<A.size()&&j<B.size()){
        if(A[i]<B[j]){
            v.push_back(A[i]);
            i++;
        }else{
            v.push_back(B[j]);
            j++;
        }
    }
    while(i<A.size()){
        v.push_back(A[i]);
            i++;
    }

    while(j<B.size()){
        v.push_back(B[j]);
            j++;
    }
    return binary_search(v,v.size(),0,v.size());

}



*/
//efficient approach using binary search 
//for better understanding watch striver video

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
   if(B.size()<A.size())return findMedianSortedArrays(B,A);
   int n1=A.size();
   int n2=B.size();
   int low=0;
   int high=n1;
   while(low<=high){
       int cut1=(low+high)>>1;
       int cut2=(n1+n2+1)/2-cut1;
       int left1=cut1==0?INT_MIN:A[cut1-1];
       int left2=cut2==0?INT_MIN:B[cut2-1];
       int right1=cut1==n1?INT_MAX:A[cut1];
       int right2=cut2==n2?INT_MAX:B[cut2];
       if(left1<=right2&&left2<=right1){
           if((n1+n2)%2==0){
               return (max(left1,left2)+min(right1,right2))/2.0;

           }else{
               return max(left1,left2);
           }
           
       }else if(left1>right2){
           high=cut1-1;
       }else{
           low=cut1+1;
       }


   }
   return 0.0;
}
