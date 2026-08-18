#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxWater=0;
        while(l<r){
            int h=min(height[l],height[r]);
            int w=r-l;
            int water  =  h*w ;
            maxWater=max(maxWater,water);

            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxWater;
    }
};
// @lc code=end

