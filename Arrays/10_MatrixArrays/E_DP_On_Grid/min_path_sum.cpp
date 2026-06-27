#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0]=grid[0][0]; //first fill
    // first col fillup->by cumulativily adding
    for(int i=1;i<m;i++){  
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    //first row fillup->by cumulativily adding
    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]+grid[0][i];
    }
    // rest filling have two paths ->come from up,come from left we chose min.
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=grid[i][j]+ min(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    
    
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Test 1: " << minPathSum(grid1) << " (Expected: 7)\n";
    
    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Test 2: " << minPathSum(grid2) << " (Expected: 12)\n";
    
    return 0;
}