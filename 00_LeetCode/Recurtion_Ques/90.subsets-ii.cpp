#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
   void subsets(int i,int n,vector<vector<int>>&ans,vector<int>&subans,vector<int>& nums){
       if(i>=n){
          ans.push_back(subans);
          return;
       }
       subans.push_back(nums[i]);
       subsets(i+1,n,ans,subans,nums);
       subans.pop_back();
       while(i+1<n && nums[i]==nums[i+1]) i++;
       subsets(i+1,n,ans,subans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subans;
        sort(nums.begin(),nums.end());
        subsets(0,nums.size(),ans,subans,nums);
        return ans;
    }
};
// @lc code=end

