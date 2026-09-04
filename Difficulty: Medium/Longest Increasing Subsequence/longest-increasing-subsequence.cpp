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