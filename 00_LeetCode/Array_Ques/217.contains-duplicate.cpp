#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()) return true;
            mp[nums[i]]=i;
        }
        return false;
    }
};
// @lc code=end

