#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool checkbox(vector<vector<char>>& board,int sr,int sc){
       unordered_map<int,int>mp;
       for(int i=sr;i<sr+3;i++){ 
          for(int j=sc;j<sc+3;j++){
             if(board[i][j] == '.') continue;
             if(mp.find(board[i][j])!=mp.end()) return false;
             mp[board[i][j]]++;
        }
       }
       return true;
    }
    bool isValidSudokuu(vector<vector<char>>& board) {

      //for rows
      for(int r=0;r<9;r++){
        unordered_map<int,int>mp;
        for(int c=0;c<9;c++){
            if(board[r][c] == '.') continue;
            if(mp.find(board[r][c])!=mp.end()) return false;
            mp[board[r][c]]++;
        }
      }  

      //for col
      for(int c=0;c<9;c++){
        unordered_map<int,int>mp;
        for(int r=0;r<9;r++){
            if(board[r][c] == '.') continue;
            if(mp.find(board[r][c])!=mp.end()) return false;
            mp[board[r][c]]++;
        }
      }
      // for 3 by 3 boxes
      for(int r=0;r<9;r+=3){
        unordered_map<int,int>mp;
        for(int c=0;c<9;c+=3){
            if(!checkbox(board, r, c)) return false;
        }
      }
      return true ; 
    }
    bool isValidSudoku(vector<vector<char>>& board) {
       return isValidSudokuu(board);
    }
};
// @lc code=end

