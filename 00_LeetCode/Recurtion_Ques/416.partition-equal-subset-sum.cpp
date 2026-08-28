#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
*/

// @lc code=start
class Solution {
public:
   bool subsets(int i,int n,vector<int>&nums,vector<int>&sub,unordered_map<int,vector<int>>&mp){

      if(i>=n){
        int sum=0;
         for(int i=0;i<sub.size();i++){
              sum+=sub[i];
         }
         if(mp.find(sum)!=mp.end() ){
            for(auto it:mp[sum]){
                if(it + sub.size()==n){
                    return true;
                }
            }
        }
         else{
             mp[sum].push_back(sub.size());
             return false;
         }
      }
     sub.push_back(nums[i]);
      if(subsets(i+1,n,nums,sub,mp)==true) return true;
      sub.pop_back();
      if(subsets(i+1,n,nums,sub,mp)==true) return true;
     return false;
 }
     bool canPartition(vector<int>& nums) {        
         vector<int>sub;
         unordered_map<int,vector<int>>mp;
         return subsets(0,nums.size(),nums,sub,mp);
       

     }
    
};
// @lc code=end

