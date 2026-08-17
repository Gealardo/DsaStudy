#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<char>>&grid,int r,int c,int row,int col){

         if (r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == '0') {
            return;
        }

       grid[r][c] = '0';

        dfs(grid,r+1,c,row,col);
        dfs(grid,r-1,c,row,col);
        dfs(grid,r,c+1,row,col);
        dfs(grid,r,c-1,row,col);

    }

    int numIslands(vector<vector<char>>& grid) {
        
     int row=grid.size();
     int col=grid[0].size();
     if(row==0 || col==0) return 0;

     int iland=0;
     for(int r=0;r<row;r++){
       for(int c=0;c<col;c++){

          if(grid[r][c] == '1'){
            iland++;
            dfs(grid,r,c,row,col);
          }

       }         
     }
     return iland;

    }
};
// @lc code=end

