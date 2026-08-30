class Solution {
  public:
    int unbound(int i,vector<int>&wt,int capacity,vector<vector<int>>&dp,vector<int>&val){
        if(i<0) return 0;
        if(dp[i][capacity]!=-1) return dp[i][capacity];
        int nottake = unbound(i-1,wt,capacity,dp,val);
        int take=0;
        if(capacity>=wt[i]) take = val[i] + unbound(i,wt,capacity-wt[i],dp,val);
        return dp[i][capacity]=max(take,nottake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return unbound(n-1,wt,capacity,dp,val);
    }
};