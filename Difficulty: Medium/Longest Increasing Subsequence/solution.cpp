class Solution {
  public:
    int LIS(int i,int j,int n,vector<int>&arr,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        int nottake = 0+LIS(i+1,j,n,arr,dp);
        int take=0;
        if(j<0 || arr[j]<arr[i]) take= 1+LIS(i+1,i,n,arr,dp);
        return dp[i][j+1]= max(take,nottake);
    }
    int lis(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return LIS(0,-1,n,arr,dp);
    }
};
