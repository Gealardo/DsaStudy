// permutation matters
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,0);  // dp[0] means=>no. of ways to get 0;
        dp[0] = 1;
        //dp[x] => x is the target , and dp[x] is the no. of ways to get x;
        for(int i=1;i<=target;i++){ // to fil the dp
            for(int j=0;j<n;j++) {// traversing arr for dp[x]=dp[x-arr[j]]+...;
               if(i>=nums[j] && dp[i] <= INT_MAX - dp[i-nums[j]]) dp[i] += dp[i-nums[j]];
            }
        } 
        return dp[target];
    }
};
