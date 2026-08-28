#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        int n=edges.size();
        vector<vector<int>>adj(V);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>indegree(V);
        for(auto &it:adj){
            for(int neigh:it){
                indegree[neigh]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        //vector<int>topo;
        int count=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            //topo.push_back(temp);
            count++;
            for(auto &it:adj[temp]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return count!=V;//topo.size()!=V;
    }
};