class Solution {
  public:
    int pattern2(int i,vector<int>&price,vector<vector<int>>&dp,int inch){
        if(i<0) return 0;
        if(dp[i][inch]!=-1) return dp[i][inch];
        int nottake = pattern2(i-1,price,dp,inch);
        int take=0;
        if(inch>=i+1) take = price[i]+ pattern2(i,price,dp,inch-(i+1));
        return dp[i][inch]=max(nottake,take);
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return pattern2(n-1,price,dp,n);
    }
};