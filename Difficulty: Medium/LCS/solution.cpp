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
