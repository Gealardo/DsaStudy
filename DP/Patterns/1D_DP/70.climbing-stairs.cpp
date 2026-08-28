#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int memo(int n,vector<int>&dp){
       if(n<2) return dp[n]=1;
       if(dp[n]!=-1) return dp[n];
       return dp[n]=memo(n-1,dp)+memo(n-2,dp);
    }
    int space_opti(int n){
        int p2=1;
        int p=1;
        for(int i=2;i<=n;i++){
            int c=p+p2;
            p2=p;
            p=c;
        }
        return p;
    }
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // return memo(n,dp);
        return space_opti(n);
    }
};
// @lc code=end

