class Solution {
  public:
    int take_nottake(int i,int n,int capacity,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
      if(n==0) return 0;
      if(i<0) return 0;
      if(dp[i][capacity]!=-1) return dp[i][capacity];
        if(capacity>=wt[i]){
           //dp[i-1][capacity] =take_nottake(i-1,n,capacity,val,wt,dp) 
           //dp[i-1][capacity-wt[i]]=take_nottake(i-1,n,capacity-wt[i],val,wt,dp)
           dp[i][capacity]=max( take_nottake(i-1,n,capacity,val,wt,dp) , val[i]+ take_nottake(i-1,n,capacity-wt[i],val,wt,dp));
        }else{
            //just don't take and move on
            dp[i][capacity]=take_nottake(i-1,n,capacity,val,wt,dp);
        }
        return dp[i][capacity];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int capacity=W; // max capacity of weight we can hold
        int n=val.size(); //no. of items
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return take_nottake(n-1,n,capacity,val,wt,dp);
    }
};