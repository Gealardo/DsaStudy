#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        int l=0;
        int r=n-1;
        int minval=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
             // 1. ADD THIS CONDITION FOR DUPLICATES
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                minval = min(minval, nums[l]);
                l++;
                r--;
                continue; // Skip to the next iteration
            }
            if(nums[mid]>=nums[l] && nums[mid]<=nums[r]){
                minval=min(minval,nums[l]);
                return minval;
            }
            else if(nums[mid]>=nums[l]){
                 minval=min(minval,nums[l]);
                 l=mid+1;
            }
            else {
                minval=min(minval,nums[mid]);
                r=mid-1;
            }
        }
        return minval;

    }
};
// @lc code=end

