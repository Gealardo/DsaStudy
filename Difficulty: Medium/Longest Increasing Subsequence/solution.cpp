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

// optimize to 1D DP
class Solution {
  public:
    int lis(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
       vector<int>dp(n,1);
       int l=1;
       for(int i=1;i<n;i++){
           for(int j=0;j<i;j++){
               if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    l=max(dp[i],l);
               }
           }
       }
       return l;
    }
};

// binary search
class Solution {
  public:
    int lis(vector<int>& arr) {
       vector<int>temp;
       int n=arr.size();
       int  l=0;
       for(int i=0;i<n;i++){
           if(temp.empty()||arr[i]>temp.back()){
               temp.push_back(arr[i]);
               l++;
           } 
           else{
               auto lb=lower_bound(temp.begin(),temp.end(),arr[i]);
               *lb=arr[i];
           }
       }
       return l;
    }
};
