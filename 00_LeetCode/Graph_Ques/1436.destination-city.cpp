#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,vector<string>>adj;
        for(auto it:paths){
           string u=it[0];
           string v=it[1];
           adj[u].push_back(v);
        }
        for(auto &it:paths){
            if(adj.find(it[1])==adj.end()) return it[1];
        }
        return "";
    }
};
// @lc code=end

