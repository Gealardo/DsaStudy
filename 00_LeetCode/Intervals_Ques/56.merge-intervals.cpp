#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>ans;
        vector<int>last=intervals[0];
        for(int i=1;i<n;i++){
           if(intervals[i][0]<=last[1]){
             last[1]=max(intervals[i][1],last[1]);
           }
           else {
              ans.push_back(last);
              last=intervals[i];
           }   
        }
        ans.push_back(last);
        return ans;
    }
};
// @lc code=end

 