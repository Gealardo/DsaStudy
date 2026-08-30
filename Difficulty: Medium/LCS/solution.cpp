// Recursive 
class Solution {
public:
    int LCS(int i,int j,string &text1,string &text2){
        if(i<0 || j<0) return 0;
        if(text1[i]==text2[j]) return 1+LCS(i-1,j-1,text1,text2);
        return 0+max(LCS(i-1,j,text1,text2),LCS(i,j-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(); int m=text2.length();
        return LCS(n-1,m-1,text1,text2);
    }
};

// rec + memo
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
// tabulation method
int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(); int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
    
        if(n==0 || m==0) return 0;
        dp[0][0] = (text1[0]==text2[0])? 1:0;
        for(int i=1;i<n;i++){
             dp[i][0] = (text1[i]==text2[0])? 1:dp[i-1][0];
        }
        for(int j=1;j<m;j++){
             dp[0][j] = (text1[0]==text2[j])? 1:dp[0][j-1];
        }
        for(int i=1; i<n;i++){
             for(int j=1;j<m;j++){
                 if(text1[i]==text2[j]) dp[i][j]= 1+dp[i-1][j-1];
                 else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
        }
    
      return dp[n-1][m-1];
    }
