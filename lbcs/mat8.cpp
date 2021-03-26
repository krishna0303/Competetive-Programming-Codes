// Given a square matrix, turn it by 90 degrees in clockwise direction without using any extra space.

// Examples: 

// Input:
// 1 2 3 
// 4 5 6
// 7 8 9  
// Output:
// 7 4 1 
// 8 5 2
// 9 6 3

// Input:
// 1 2
// 3 4
// Output:
// 3 1
// 4 2 



 


#include<bits/stdc++.h>
using namespace std;



//Method1
// Let size of row and column be 3. 
// During first iteration – 
// a[i][j] = Element at first index (leftmost corner top)= 1.
// a[j][n-1-i]= Rightmost corner top Element = 3.
// a[n-1-i][n-1-j] = Righmost corner bottom element = 9.
// a[n-1-j][i] = Leftmost corner bottom element = 7.
// Move these elements in the clockwise direction. 
// During second iteration – 
// a[i][j] = 2.
// a[j][n-1-j] = 6.
// a[n-1-i][n-1-j] = 8.
// a[n-1-j][i] = 4. 
// Similarly, move these elements in the clockwise direction. 

void rotate90Clockwise1(int **a,int N)
{
 
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

//Method2
// Method 2:

// Approach: The approach is based on the pattern made by indices after rotating the matrix. Consider the following illustration to have a clear insight into it.

// Consider a 3 x 3 matrix having indices (i, j) as follows. 

// 00 01 02 
// 10 11 12 
// 20 21 22

// After rotating the matrix by 90 degrees in clockwise direction, indices transform into
// 20 10 00  current_row_index = 0, i = 2, 1, 0 
// 21 11 01 current_row_index = 1, i = 2, 1, 0 
// 22 12 02  current_row_index = 2, i = 2, 1, 0

// Observation: In any row, for every decreasing row index i, there exists a constant column index j, such that j = current_row_index.
void rotate90Clockwise2(int **a,int n)
{
     
 
    // Traverse each cycle
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            cout<<a[j][i]<<" ";

        }
        cout<<endl;
    }
}
int main(){
    int n1;
    cin>>n1;
    int **arr=new int*[n1];
    for(int i=0;i<n1;i++){
        arr[i]=new int[n1];
        for(int j=0;j<n1;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    // int n=n1;
    // while(n!=1){
    //     int topleft=0,topright=0,btmleft=n-1,btmright=n-1;
    // while(topleft<n-1 &&topright<n-1){
    //     int temp=arr[btmleft][0];
    //     arr[btmleft][0]=arr[n-1][btmright];
    //     arr[n-1][btmright]=arr[topright][n-1];
    //     arr[topright][n-1]=arr[0][topleft];
    //     arr[0][topleft]=temp;
    //     topleft++;
    //     topright++;
    //     btmleft--;
    //     btmright--;


    // }
    // n=n/2;

    // }
    rotate90Clockwise1(arr,n1);
    
    for(int i=0;i<n1;i++){
        
        for(int j=0;j<n1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    rotate90Clockwise2(arr,n1);


    return 0;
}
