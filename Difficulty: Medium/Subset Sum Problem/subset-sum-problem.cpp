class Solution {
  public:
    bool summ(int i,int n,vector<int>&arr,vector<vector<int>>&dp,int k,int s,int rem){
        if(s==k) return true;
        if(i<0) return false;
        if(dp[i][rem]!=-1) return dp[i][rem];
        bool nottake = summ(i-1,n,arr,dp,k,s,rem); 
        bool take=false;
        if(rem>=arr[i]) take = summ(i-1,n,arr,dp,k,s+arr[i],rem-arr[i]);
        return dp[i][rem]=take||nottake ;
    } 
       
    bool isSubsetSum(vector<int>& arr, int sum) {
         int n=arr.size();
         vector<vector<int>>dp(n,vector<int>(sum+1,-1));
         return summ(n-1,n,arr,dp,sum,0,sum);
    }
};