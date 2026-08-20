#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    void findcombi(int i,int n,vector<int>&candidates,int k,vector<vector<int>>&ans,int sum,vector<int>&subans){
       if(sum>k) return;
       if(sum==k) {
        ans.push_back(subans);
          return;
       }
       if(i>=n) return; 
       
        sum+=candidates[i];
        subans.push_back(candidates[i]);
        findcombi(i,n,candidates,k,ans,sum,subans);

        sum-=candidates[i];
        subans.pop_back();
        findcombi(i+1,n,candidates,k,ans,sum,subans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subans;
        vector<vector<int>>ans;
        findcombi(0,candidates.size(),candidates,target,ans,0,subans);
        return ans;
    }
};
// @lc code=end

