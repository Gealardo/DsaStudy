#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        queue<pair<int,int>>q;
        int i=0; int j=0;
        if(grid[i][j]==1 || grid[n][n]==1) return -1;
        if(n==-1) return 1;
        q.push({i,j});
        int len=1;
        grid[i][j]=1;

        vector<pair<int,int>>direction={
            {-1,-1},
            {-1,0},
            {0,-1},
            {0,1},
            {1,-1},
            {1,1},
            {1,0},
            {-1,1}
        };
        while(!q.empty()){
            int x=q.size();
            for(int a=0;a<x;a++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r==n && c==n) return len;

                for(auto d:direction){
                    int nr=r+d.first;
                    int nc=c+d.second;
                    if(nr<=n && nr>=0 && nc<=n && nc>=0 && grid[nr][nc]==0){
                        grid[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            len++;
            

        }
        return -1;
    }
};
// @lc code=end

