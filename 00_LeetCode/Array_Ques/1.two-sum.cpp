#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
              
            int tar=target-nums[i]; // ele1(tar) + ele2(nums[i]) = target
              if(mp.find(tar)!=mp.end()){ // if it already exist 
                    ans.push_back(mp[tar]); 
                    ans.push_back(i);
              }
              mp[nums[i]]=i; 
        }
        return ans;
    }
};

