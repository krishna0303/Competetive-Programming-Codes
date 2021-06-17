// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 /*

 idea is to right shift one by one and check if and operation with 1 is resulting some non negative number or not if yes then 
 increase count

 N=101010->>(1 right shift)->010101&000001=>000001(which is on negative hence increse count of set bit)
 
 
 */
class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int count=0;
        for(int i=0;i<32;i++){
            
            if(N&1){
                count+=1;
            }
            N=N>>1;
        }
        return count;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends