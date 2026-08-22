#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
       
        int x1=0;
        for(int i=0;i<n;i++){
            x1^=nums[i];
        }
        int x2=0;
        for(int i=0;i<=n;i++){
            x2^=i;
        }
        return x1^x2;

    }
};
// @lc code=end

