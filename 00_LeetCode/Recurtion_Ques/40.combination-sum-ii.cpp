#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    void findcombi(int i,int n,vector<int>&candidates,int k,vector<vector<int>>&ans,int sum,vector<int>&subans){
       if(sum>k) return;
       if(sum==k){
            ans.push_back(subans);
            return;
        }
        if(i>=n) return;
        sum+=candidates[i];
        subans.push_back(candidates[i]);
        findcombi(i+1,n,candidates,k,ans,sum,subans);

        sum-=candidates[i];
        subans.pop_back();
        while(i+1<n && candidates[i]==candidates[i+1]) i++;
        findcombi(i+1,n,candidates,k,ans,sum,subans);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>subans;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        findcombi(0,candidates.size(),candidates,target,ans,0,subans);
        return ans;
    }
};
// @lc code=end

