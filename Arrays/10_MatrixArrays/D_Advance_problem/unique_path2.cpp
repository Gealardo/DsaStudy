#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(int m,int n,vector<vector<int>>& obstacleGrid) {
    if(m<0 || n<0) return 0;
    if(obstacleGrid[m][n]== 1 ) return 0;
    if(m==0 && n==0) return 1;

    int up=uniquePathsWithObstacles(m-1,n,obstacleGrid);
    int left=uniquePathsWithObstacles(m,n-1,obstacleGrid);

    return up+left;
   
}
//---------------------------------------------------------------------------------
int funmemo(int m,int n,vector<vector<int>>&obstacleGrid ,vector<vector<int>>&dp){

   if(m<0 || n<0 ) return 0;
   if(obstacleGrid[m][n]== 1 ) return 0;
   if(m==0 && n==0) return dp[m][n]=1;
   if(dp[m][n]!=-1) return dp[m][n];
   return dp[m][n]=funmemo(m-1,n,obstacleGrid,dp)+funmemo(m,n-1,obstacleGrid,dp);

}
//for memo
int uniquePathsWithObstaclesMemo(vector<vector<int>>&obstacleGrid){
    int m=obstacleGrid.size()-1;
    int n=obstacleGrid[0].size()-1;
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return funmemo(m,n,obstacleGrid,dp);
}
//----------------------------------------------------------------------------------

int main() {
    vector<vector<int>> grid1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Test 1 (3x3 with middle obstacle): " << uniquePathsWithObstacles(3-1,3-1,grid1) << " (Expected: 2)\n";

    vector<vector<int>> grid2 = {
        {0, 1},
        {0, 0}
    };
    cout << "Test 2 (2x2): " << uniquePathsWithObstacles(2-1,2-1,grid2) << " (Expected: 1)\n";

    vector<vector<int>> grid3 = {
        {1, 0},
        {0, 0}
    };
    cout << "Test 3 (Start blocked): " << uniquePathsWithObstaclesMemo(grid3) << " (Expected: 0)\n";

    return 0;
}