#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();

        sort(nums.begin(),nums.end());

        if(n<4) return ans;

        for(int i=0;i<n-3;i++){
            // e1 + e2 +e3 +e4 =target;
            if(i-1>=0 && nums[i]==nums[i-1]) continue;

            long long e1=nums[i];
            long long t= target-e1;

            for(int j=i+1;j<n-2;j++){
                // e2 + e3 + e4 = t;
                if(j-1>=i+1 && nums[j]==nums[j-1]) continue;

                long long e2 = nums[j];
                long long tt = t-e2;
                int l=j+1;
                int r=n-1;

                while(l<r){
                    long long sum=(long long)nums[l]+nums[r];

                    if(tt==sum){
                       vector<int>a={(int)e1,(int)e2,nums[l],nums[r]};
                       ans.push_back(a);
                       while(l+1<r && nums[l]==nums[l+1]) l++;
                       while(r-1>l && nums[r]==nums[r-1]) r--;
                       r--; l++;
                    }

                    else if(tt>sum) l++;
                    
                    else r--;  
                }
            }
        }
        return ans;
    }
};
// @lc code=end

