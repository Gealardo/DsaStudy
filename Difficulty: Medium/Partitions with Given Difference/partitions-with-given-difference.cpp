class Solution {
  public:
    int count(int i,vector<int>&arr,vector<vector<int>>&dp,int rem){
        if(i<0){
          if(rem==0) return 1;
          return 0;
        }
        if(dp[i][rem]!=-1) return dp[i][rem];
        int nottake=count(i-1,arr,dp,rem);
        int take=0;
        if(rem>=arr[i]) take=count(i-1,arr,dp,rem-arr[i]);
        return dp[i][rem]= nottake + take;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n=arr.size();
        int s=0;
        for(auto &x:arr){
            s+=x;
        }
        if((s+diff)%2!=0) return 0;
        int target=(s+diff)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return count(n-1,arr,dp,target);
    }
};