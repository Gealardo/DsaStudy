#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        vector<int>ans;
        int n=numbers.size();
        int h=n-1;
        while(l<h){
            int sum=numbers[l] + numbers[h];
            if(sum==target){
               ans.push_back(l+1);
               ans.push_back(h+1);
               return ans;
            }
            else if(sum>target) h--;
            else l++;
        }
        return ans;
    }
};
// @lc code=end

