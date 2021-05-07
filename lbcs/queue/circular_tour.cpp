/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int count=0;   //to count the number times we iterate on loop if we iterate two times in a loop and didn't get any index then there is no such type of point available so return -1
       int balance=0;   //extra petrol 
       int rear=0;
       int front=0;
       
       int ans=-1;
       bool flag=false;  //to handle i.e escape initial front==rear condition .
       while(count!=2){   //it will run loop for two times
           balance=(p[rear].petrol+balance-p[rear].distance);     //caluclating remain petrol 
           if(balance<0){
               
               if(rear==n-1){        //if rear reach to end of aaray then it should be again start with 0th index and 
                                     //and count is increase by 1 because 1 times complete loop has been traversed.
                   rear=0;
                   count+=1;
               }else{
                   rear+=1;        //otherwise increament in rear
               }
               front=rear;        //if balance<0 it means value comes negative so we have to shift our front and rear to the
                                   //next of current rear and set balance=0 and make flag=false because now we are shifting front and rear to the same index and it will be same so for next condition in else loop it should not be considered
               balance=0;
               flag=false;
              
           }else{
               
               
               if(flag&&rear==front){  //if flag==true means if after iterating over a loop if again front==rear
                   ans=front;           //the that index is our answer
                   break;               //break the loop
               }
               if(rear==n-1){       //same for handling last value of array
                   rear=0;
                   count+=1;
               }else{
                  rear+=1;         //increament rear by 1
               }
              
              flag=true;         //this means after escaping intinital front==rear if again this condition will become tru it means we got our answer.
               
           }
       }
       return ans;
       
       
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends