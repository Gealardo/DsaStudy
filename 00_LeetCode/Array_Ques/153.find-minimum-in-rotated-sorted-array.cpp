#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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

