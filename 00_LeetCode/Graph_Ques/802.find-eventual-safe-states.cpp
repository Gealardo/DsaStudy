#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
public:
     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++){
            //adj[i].push_back(graph[i]); reverse of this...
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        vector<int>indegree(V,0);
        for(auto &it:adj){
            for(auto &neighboor:it){
                indegree[neighboor]+=1;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            topo.push_back(temp);
            for(auto &it:adj[temp]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};
// @lc code=end

