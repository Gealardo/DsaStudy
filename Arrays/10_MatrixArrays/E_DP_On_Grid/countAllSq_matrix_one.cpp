
#include<bits/stdc++.h>
using namespace std;

// worst method ------------------------------------
int solvee(int i,int j,vector<vector<int>>&grid){
     if (i >= grid.size() || j >= grid[0].size()) return 0;
    if(grid[i][j]==0) return 0;
    if(grid[i][j]==1){

        int right=solvee(i,j+1,grid);
        int diagonal=solvee(i+1,j+1,grid);
        int down=solvee(i+1,j,grid);


        return 1+min({right,diagonal,down});

    }
    return 0;
}
int reccurtion(vector<vector<int>>&grid){
    int result =0;
    int m=grid.size();
    int n=grid[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            result+=solvee(i,j,grid);
        }
    }
    return result;
}
//--------------------------------------------------


// recur + memo method--------------------------------------

int solve2(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
     if (i >= grid.size() || j >= grid[0].size()) return 0;
    if(grid[i][j]==0) return dp[i][j]=0;
    
    if(grid[i][j]==1){

        if(dp[i][j]!=-1) return dp[i][j];
        
        int right=solve2(i,j+1,grid,dp);
        int diagonal=solve2(i+1,j+1,grid,dp);
        int down=solve2(i+1,j,grid,dp);


        return dp[i][j]=1+min({right,diagonal,down});

    }
    return 0;
}
int reccMemo(vector<vector<int>>&grid){
    int result =0;
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            result+=solve2(i,j,grid,dp);
        }
    }
    return result;
}


//---------------------------------------------------------------------

int tabulation(vector<vector<int>>&grid){
   vector<vector<int>>dp2=grid;
   int total_sum=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            //for i>0,j>0 and grid[i][i]==1
            if(grid[i][j]==1 && i>0 && j>0){
                dp2[i][j]=min({dp2[i-1][j],dp2[i-1][j-1],dp2[i][j-1]})+1;
            }
            // for first row ,first col, dp=grid same filled;

            total_sum+=dp2[i][j];
           
        }
    }
    return total_sum;
}

int main(){
    vector<vector<int>>grid={
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1},
    };
    cout<<reccurtion(grid)<<endl;

    cout<<reccMemo(grid)<<endl;

    cout<<tabulation(grid)<<endl;
}