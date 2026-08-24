#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int count=0;
        vector<int>last=intervals[0];
        for(int i=1;i<n;i++){
             if(intervals[i][0]<last[1]){
                count++;
                last[1] = min(last[1], intervals[i][1]);
             }
             else{
                last=intervals[i];
             }
        }
        return count;
    }
};
// @lc code=end

