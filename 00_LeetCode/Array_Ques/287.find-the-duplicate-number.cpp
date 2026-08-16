#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        int h=n-1 ;//consedring there is one dublicate.
        while(l<=h){
            int m=l+(h-l)/2;
            int count=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=m) count++;
            }
              
            if(count<=m) l=m+1;
            else h=m-1;

        }
        return l; // l>h; l become ans;
    }
};
// @lc code=end

