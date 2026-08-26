#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int>&visited){
        visited[i]=1;
        for(auto &it:adj[i]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int count=0;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};
// @lc code=end

