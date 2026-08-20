#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
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
       subsets(i+1,n,ans,subans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subans;
        subsets(0,nums.size(),ans,subans,nums);
        return ans;
    }
};
// @lc code=end

