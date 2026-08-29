class Solution {
  public:
    bool found(int i,int n,vector<int>&arr,vector<vector<int>>&dp,int rem){
        if(rem==0) return true;
        if(i<0) return false;
        if(dp[i][rem]!=-1) return dp[i][rem];
        bool nottake=found(i-1,n,arr,dp,rem);
        bool take=false;
        if(rem>=arr[i]) take=found(i-1,n,arr,dp,rem-arr[i]);
        return dp[i][rem]=take||nottake;
     }
    bool equalPartition(vector<int>& arr) {
        int s=0;
        int n=arr.size();
        for(auto &x:arr){
            s+=x;
        }
        if(s%2!=0) return false;
        int target=s/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return found(n-1,n,arr,dp,target);
     }
};