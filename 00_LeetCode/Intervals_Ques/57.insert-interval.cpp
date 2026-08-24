#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int n=intervals.size();
       vector<vector<int>>ans;
       int idx=0;

       
       while(idx<n && intervals[idx][1]<newInterval[0]) ans.push_back(intervals[idx++]);

      
       while(idx<n && intervals[idx][0]<=newInterval[1])
       {
          newInterval[0]=min( newInterval[0],intervals[idx][0] );
          newInterval[1]=max( newInterval[1],intervals[idx][1] ); idx++;
       }
       ans.push_back(newInterval);

       
       while(idx<n) ans.push_back(intervals[idx++]);

       return ans;
    }
};
// @lc code=end

