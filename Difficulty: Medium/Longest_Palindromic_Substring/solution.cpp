class Solution {
public:
    string substring(string &s1, string &s2){
        int n=s1.length();
        int m=s2.length();
        string s="";
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(s.length() < dp[i][j] && (n - j) == (i - dp[i][j])) {
                         s = s1.substr(i - dp[i][j], dp[i][j]); 
                    }
                }
                else dp[i][j]=0;
            }
        }
        return s;
    } 
    string longestPalindrome(string s) {
        if(s.length()==1 || s.length()==0) return s;
        string s1=s;
        string temp=s;
        reverse(temp.begin(),temp.end());
        string s2=temp;
        return substring(s1,s2);
    }
};
