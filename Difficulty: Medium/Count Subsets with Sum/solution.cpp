class Solution {
  public:
    int countsubset(int i,vector<int>&arr,vector<vector<int>>&dp,int rem){
        if(i<0){
            if(rem==0) return 1;
            else return 0;
        }
        if(dp[i][rem]!=-1) return dp[i][rem];
        int nottake = countsubset(i-1,arr,dp,rem);
        int take=0;
        if(rem>=arr[i]) take+=countsubset(i-1,arr,dp,rem-arr[i]);
        return dp[i][rem]=take + nottake;
    }
    int perfectSum(vector<int>& arr, int target) {
       int n=arr.size();
       vector<vector<int>>dp(n,vector<int>(target+1,-1));
       return countsubset(n-1,arr,dp,target);
    }
};
