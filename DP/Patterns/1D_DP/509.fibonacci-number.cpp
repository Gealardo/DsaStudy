#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int recursive(int n){
        if(n==1 || n==0) return n;
        return recursive(n-1)+recursive(n-2);
    }
    int memo(int n,vector<int>&dp){
        if(n==0) return dp[n]=0;
        if(n==1) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=memo(n-1,dp)+memo(n-2,dp);
    }
    int tabu(int n,vector<int>&dp2){
       dp2[0]=0;
       dp2[1]=1;
       for(int i=2;i<=n;i++){
        dp2[i]=dp2[i-2]+dp2[i-1];
       }
       return dp2[n];
    }
    int space_opti(int n){
       int prev2=0;
       int prev=1;
       for(int i=2;i<=n;i++){
           int  curr=prev+prev2;
           prev2=prev;
           prev=curr;
       }
       return prev;
    }
    
    int fib(int n) {
        if(n==0) return 0;
       // return recursive(n);

        //   vector<int>dp(n+1,-1);
        //   return memo(n,dp);

        //   vector<int>dp2(n+1,-1);
        //   return tabu(n,dp2);

        return space_opti(n);
    }
};
// @lc code=end

