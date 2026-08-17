#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
//    struct lemda{
//      bool operator()(const pair<double,vector<int>>&a,const pair<double,vector<int>>&b){
//          return a.first > b.first;
//      }
//    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0]; int y=points[i][1];
            int distance1= (x*x) + (y*y) ;
           // double d=sqrt(distance1);
            vector<int>point={x,y};
            pq.push({distance1,point});
        }
        for(int i=0;i<k;i++){
          
            ans.push_back(pq.top().second);
            pq.pop();

        }

        return ans;

    }
};
// @lc code=end

