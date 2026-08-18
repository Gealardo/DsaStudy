#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=0;
        for(int i=0;i<n;i++){
            r=max(r,piles[i]);
        }
        while(l<=r){

          int m = l+(r-l)/2;
          // let if koko eat m banana per hour will he finish?
          long long timetaken=0;
          for(int i=0;i<n;i++){
              timetaken += (piles[i]+m-1)/m;
          }
          
          if(timetaken > h) l=m+1;
          else r=m-1;
        }
        return l;
    }
};
// @lc code=end

