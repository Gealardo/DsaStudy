#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>>ans; 
       sort(nums.begin(),nums.end());
       if(n<3) return  ans;
       for(int i=0; i<n-2;i++){

         if(i-1>=0 && nums[i]==nums[i-1]) continue;  //skip duplicate      
         int  e1 = nums[i];        
         int target = -(e1);
          
          int l=i+1;
          int r=n-1;
          while(l<r){
            int sum=nums[l]+nums[r];
            if(sum==target){
                vector<int>ans1={nums[i],nums[l],nums[r]};
                ans.push_back(ans1);

                while(l+1 < r && nums[l]==nums[l+1]) l++;
                while(r-1 > l && nums[r-1]==nums[r]) r--;
                l++;
                r--;
            }
            else if(sum<target) l++;
            else r--;
          }

       }
       return ans;
    }
};
// @lc code=end

