class Solution {
public:
    int LCS(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j] = 1+LCS(i-1,j-1,text1,text2,dp);
        return dp[i][j] = 0+max(LCS(i-1,j,text1,text2,dp),LCS(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(); int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return LCS(n-1,m-1,text1,text2,dp);
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(); int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        if(n==0 || m==0) return 0;
        for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
             if(text1[i-1]==text2[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
             }
             else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
          }
        }
        return dp[n][m];
    }
};


//if need to print, we have to backtrack
 string subsequence = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            // If characters match, they belong in our subsequence
            if (text1[i - 1] == text2[j - 1]) {
                subsequence += text1[i - 1];
                i--;
                j--;
            } 
            // If they don't match, move in the direction of the larger DP value
            else if (dp[i - 1][j] >= dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
