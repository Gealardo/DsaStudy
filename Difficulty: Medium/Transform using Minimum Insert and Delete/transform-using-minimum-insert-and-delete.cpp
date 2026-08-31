class Solution {
 public:
     int LCS(string &word1, string &word2){
         int n=word1.length(); int m=word2.length();
         if(n==0 || m==0) return 0;
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
                 if(word1[i-1]==word2[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                 else dp[i][j] = 0+ max(dp[i-1][j],dp[i][j-1]);
             }
         }
         return dp[n][m];
     }
     int minDistance(string word1, string word2) {
         int common=LCS(word1,word2);
         int step1 = word1.length()-common;
         int step2 = word2.length()-common;
         return step1+step2;
     }
        
    int minOperations(string &s1, string &s2) {
      return minDistance(s1,s2);  
    }
};