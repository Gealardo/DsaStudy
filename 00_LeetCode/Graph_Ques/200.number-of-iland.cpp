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
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
        visited[node]=1;
        for(auto &it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>adj(n*m);
        vector<int>dr={-1,1,0,0};
        vector<int>dc={0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '0') continue;
                int node=i*m +j;
                for(int k=0;k<4 ;k++){
                    int ni=i+dr[k];
                    int nj=j+dc[k];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                         int neighbour = ni * m + nj;
                        adj[node].push_back(neighbour);
                    }
                }
            }
        }
        vector<int>visited(n*m);
        int iland=0;
        for(int i=0;i<(n*m);i++){
            if(grid[i/m][i%m] == '1' && !visited[i]){
                iland++;
                dfs(i,adj,visited);
            }
        }
        return iland;
    }
};
// @lc code=end

