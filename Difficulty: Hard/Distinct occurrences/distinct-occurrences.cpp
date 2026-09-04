class Solution {
  public:
    int count(int i,int j,string &txt,string &pat,vector<vector<int>>&dp){
        if(j<0) return 1; if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;int nottake=0;
        if(txt[i]==pat[j]){
           take= count(i-1,j-1,txt,pat,dp) + count(i-1,j,txt,pat,dp);
        }
        else nottake= count(i-1,j,txt,pat,dp);
        return dp[i][j]=take+nottake;
    }
    int subseqCount(string &txt, string &pat) {
        vector<vector<int>>dp(txt.length()+1,vector<int>(pat.length()+1,-1));
        return count(txt.length()-1,pat.length()-1,txt,pat,dp);
    }
};