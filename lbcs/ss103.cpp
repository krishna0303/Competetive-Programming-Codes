// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is rotated at an unknown pivot 
// index k (0 <= k < nums.length) such that
//  the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
//  For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the rotation and an integer target, return the index of target if it is in nums, 
// or -1 if it is not in nums.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BS(vector<int>& nums,int i,int j, int target){
        int index=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                index=mid;
                break;
            }else if(nums[mid]>target){
                j-=1;                
            }else{
                i+=1;
            }


        }
        return index;
    }
    int Pivot(vector<int>& nums,int i,int j, int target){
         int index=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]>nums[mid+1]){
                index=mid;
                break;
                
                
            }
            if(nums[i]>=nums[mid]){
                j-=1;
            }else{
                i+=1;
            }

        }
        return index;
    }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            if(target==nums[0]){
                return 0;

            }else{
                return -1;
            }
        }
        int pivot=Pivot(nums,0,n-1,target);
        // cout<<pivot<<endl;
        if(pivot==-1){
            return BS(nums,0,n-1,target);
        }
        if(nums[pivot]==target){
            return pivot;
        }
        if(nums[0]<=target){
            return BS(nums,0,pivot,target);
        }else{
            return BS(nums,pivot+1,n-1,target);
            
        }
        
        
    }
};