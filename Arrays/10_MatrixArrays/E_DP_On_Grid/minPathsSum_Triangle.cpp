#include<bits/stdc++.h>
using namespace std;
// pure reccursion ----space O(N)
int min_path(int m,int n,vector<vector<int>>&grid){
    if(m==grid.size()-1) return grid[m][n];
   int  down= grid[m][n]+ min_path(m+1,n,grid);
   int  diagonal=grid[m][n]+min_path(m+1,n+1,grid);
   
   return min(down,diagonal);

}

//---memo+rec----------------------------------------------------------------
int min_path2(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
      if(m==grid.size()-1) return dp[m][n]=grid[m][n];
      if(dp[m][n]!=-1) return dp[m][n];
      int  down= grid[m][n]+ min_path2(m+1,n,grid,dp);
      int  diagonal=grid[m][n]+min_path2(m+1,n+1,grid,dp);
      return dp[m][n]=min(down,diagonal);
}
int helper_memo(vector<vector<int>>&grid){
    int row=grid.size();
    
    vector<vector<int>>dp(row,vector<int>(row,-1));
    return min_path2(0,0,grid,dp);
}
//-------------------------tabulation------------------------------------------------

int tabulation(vector<vector<int>>&grid,vector<vector<int>>&dp2){
    
     
    // fill the first element in dp grid
       dp2[0][0]=grid[0][0];


    // fill the first col in dp grid
    for(int i=1;i<grid.size();i++){
        dp2[i][0]=dp2[i-1][0]+grid[i][0];
    }

    
    //fill the last el of each row in dp grid
    for(int i=1;i<grid.size();i++){
        dp2[i][grid[i].size()-1]=dp2[i-1][grid[i].size()-2]+grid[i][grid[i].size()-1];
    }

    
    // fill the middle part as well
    for(int i=2;i<grid.size();i++){
        for(int j=1;j<grid[i].size()-1;j++){
            dp2[i][j]=grid[i][j]+min(dp2[i-1][j],dp2[i-1][j-1]);
      }
    }

   // the min among the last row...
   int minans=INT_MAX;
   for(int i=0;i<grid[grid.size()-1].size();i++){
        minans=min(minans,dp2[grid.size()-1][i]);
    }

  return minans;

}


int main(){

    vector<vector<int>>grid={
        {1},
        {2,3},
        {4,5,6},
        {7,8,9,1},
    };
    int ans=min_path(0,0,grid);
    cout<<ans<<endl;
    cout<<helper_memo(grid)<<endl;

    int row=grid.size();
    vector<vector<int>>dp2(row,vector<int>(row,0));
    cout<<tabulation(grid,dp2)<<endl;
   
}