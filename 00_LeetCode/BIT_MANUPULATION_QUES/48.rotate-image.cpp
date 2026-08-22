#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int r=0;r<n;r++){
           int l=0,h=m-1;
           while(l<h){
              swap(matrix[r][l],matrix[r][h]);
              l++;
              h--;
           }
      }
      return;
    }
};
// @lc code=end

