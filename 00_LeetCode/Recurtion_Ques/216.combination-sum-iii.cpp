#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
   void findsubset(int i,int n,vector<int>&arr,vector<vector<int>>&ans,vector<int>&subans,int k,int sum){

       if(sum==n && subans.size()==k){
          ans.push_back(subans);
          return;
       }
       if(sum>n || subans.size()>k) return;
      
       if(i>=9) return;

       sum+=arr[i];
       subans.push_back(arr[i]);
       findsubset(i+1,n,arr,ans,subans,k,sum);

       sum-=arr[i];
       subans.pop_back();
       findsubset(i+1,n,arr,ans,subans,k,sum);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        for(int i=1;i<=9;i++){
            arr.push_back(i);
        }
        vector<int>subans;
        vector<vector<int>>ans;
        findsubset(0,n,arr,ans,subans,k,0);
        return ans;
    }
};
// @lc code=end

