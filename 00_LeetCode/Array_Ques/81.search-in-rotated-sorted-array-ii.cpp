#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target==nums[mid]){
                return true;
            }
            else if (nums[l]==nums[mid] && nums[mid]==nums[r]){
                l++;
                r--;
                continue;
            }
            else if( nums[l]<= nums[mid] ){
                     if(nums[l]<=target && nums[mid]>target){
                        r=mid-1;
                     }
                     else {
                        l=mid+1;
                     }
            }
            else {
                if(nums[mid]<target && nums[r]>=target){
                    l=mid+1;
                }
                else {
                    r=mid-1;
                }
            }
        }
        return false ;
    }
};
// @lc code=end

