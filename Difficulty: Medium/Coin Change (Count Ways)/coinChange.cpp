class Solution {
  public:
    int fun(int i,vector<int>&coins,vector<vector<int>>&dp,int rem){
        if(i<0){
            return (rem==0)? 1:0 ;
        }
        if(dp[i][rem]!=-1) return dp[i][rem];
        int nottake=fun(i-1,coins,dp,rem);
        int take=0;
        if( rem>=coins[i] ) take=fun(i,coins,dp,rem-coins[i]);
        return dp[i][rem] = take + nottake ;
    }
    int count(vector<int>& coins, int sum) {
       int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(sum+1,-1));
       return fun(n-1,coins,dp,sum);    
    }
};

// if junt need minimum coins to get the target sum/money
class Solution {
public:
     int fun(int i,vector<int>&coins,vector<vector<int>>&dp,int rem){
        if(i<0){
            return (rem==0)? 0:1e9 ;
        }
        if(dp[i][rem]!=-1) return dp[i][rem];
        int nottake=fun(i-1,coins,dp,rem);
        int take=1e9;
        if( rem>=coins[i] ) take= 1 + fun(i,coins,dp,rem-coins[i]);
        return dp[i][rem] = min(take , nottake) ;
    }
    int count(vector<int>& coins, int sum) {
       int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(sum+1,-1));
       int ans=fun(n-1,coins,dp,sum);
       return (ans>=1e9)? -1:ans;    
    }
    int coinChange( vector<int>& coins,int amount) {
        return count(coins,amount);
    }
};
