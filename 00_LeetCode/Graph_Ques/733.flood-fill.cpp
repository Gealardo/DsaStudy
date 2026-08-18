#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    
    void dfs(vector<vector<int>>&image,int sr, int sc,int initialColor ,int color,int row,int col) {
         
        if(sr>=row || sc>=col ||sr<0 || sc<0) return ;
        
        if (image[sr][sc] != initialColor || image[sr][sc] == color) {
        return;
    }
        image[sr][sc]=color;

        dfs(image,sr-1,sc,initialColor,color,row,col);
        dfs(image,sr+1,sc,initialColor,color,row,col);
        dfs(image,sr,sc-1,initialColor,color,row,col);
        dfs(image,sr,sc+1,initialColor,color,row,col);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int row=image.size();
        if(row==0 ) return image;
        int col=image[0].size();

        int initialColor = image[sr][sc];
    
     
       if (initialColor != color) {
         dfs(image, sr, sc, initialColor, color, row, col);
       }

        return image;
    }
};
// @lc code=end

