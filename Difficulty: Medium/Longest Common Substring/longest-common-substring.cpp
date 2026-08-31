class Solution {
  public:
    int fun(int i,int j,string &s1,string &s2,vector<vector<int>>&dp,int &len){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]){
              dp[i][j]= 1+fun(i-1,j-1,s1,s2,dp,len);
              len=max(len,dp[i][j]);
              return dp[i][j];
        }
        return dp[i][j]=0;
    }
    int longCommSubstr(string& s1, string& s2) {
        int n=s1.length();
        int m= s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int len=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == -1) {
                    fun(i, j, s1, s2, dp, len);
                }
            }
        }
        return len;
    }
};


class Solution {
  public:
   
    int longCommSubstr(string& s1, string& s2) {
        int n=s1.length();
        int m= s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int len=0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
               if(s1[i-1]==s2[j-1]) {
                   dp[i][j]=1+(dp[i-1][j-1]);
                   len=max(len,dp[i][j]);
               }
               else  dp[i][j]=0;
            }
          }
        return len;
        }
};


class Solution {
  public:
   
    int longCommSubstr(string& s1, string& s2) {
        int n=s1.length();
        int m= s2.length();
        
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        int len=0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
               if(s1[i-1]==s2[j-1]) {
                   curr[j]=1+ prev[j-1];
                   len=max(len,curr[j]);
               }
               else  curr[j]=0;
            }
            prev=curr;
          }
        return len;
        }
};
