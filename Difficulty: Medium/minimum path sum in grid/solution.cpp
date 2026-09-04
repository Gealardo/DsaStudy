class Solution {
public:
    int mini(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if (i == 0 && j == 0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        // go up
        int up= grid[i][j]+mini(i-1,j,grid,dp);
        //right
        int lft= grid[i][j]+mini(i,j-1,grid,dp);
        return dp[i][j]=min(up,lft);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return mini(m-1,n-1,grid,dp);
    }
};
