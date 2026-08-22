#include<bits/stdc++.h>
using namespace  std;


/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    void permutation(vector<int>& nums,vector<int>&subans, vector<vector<int>>&ans,unordered_map<int,bool>&taken){ 
         if(subans.size()==nums.size()){
            ans.push_back(subans);
            return;
         }
         for(int i=0;i<nums.size();i++){
            if(taken[nums[i]]==false){
                taken[nums[i]]=true;
                subans.push_back(nums[i]);
                permutation(nums,subans,ans,taken);
                taken[nums[i]]=false;
                subans.pop_back();
            }
         }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>subans;
        vector<vector<int>>ans;
        unordered_map<int,bool>taken;
        permutation(nums,subans,ans,taken);
        return ans;
    }
};
// @lc code=end

