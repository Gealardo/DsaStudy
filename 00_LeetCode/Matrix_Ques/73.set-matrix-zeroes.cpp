#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
      void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool row0=false;
        bool col0=false;
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }
        
        // 2. Check if the first column has any zeros
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        for(int i=1;i<n;i++){
             for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
             }
        }
        for(int c=1;c<m;c++){
            if(matrix[0][c]==0){
                for(int r=1;r<n;r++){
                    matrix[r][c]=0;
                }
            }
        }
        for(int r=1;r<n;r++){
            if(matrix[r][0]==0){
                for(int c=1;c<m;c++){
                     matrix[r][c]=0;
                }
            }
        }
     
        // 1st column have zero
        if(col0){
            for(int i=0;i<n;i++){
               if(matrix[i][0]==0){
                  for(int r=0;r<n;r++){
                    matrix[r][0]=0;
                  }
                  break;
               }
            }
        }
        //1st row have zero
        if(row0){
             for(int j=0;j<m;j++){
                 if(matrix[0][j]==0){
                       for(int c=0;c<m;c++){
                         matrix[0][c]=0;
                      }
                      break;
                 }
             }
        }
       return;
    }
};
// @lc code=end

