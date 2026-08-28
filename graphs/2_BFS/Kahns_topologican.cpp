#include<bits/stdc++.h>
using namespace std;

class Solution {
     //topological sort->
        /*
        adj list
        take a stack push node during dfs
        return stack element in reverse order
        */
    // method 2 bfs/Kahn's algo    
  public:
    void foundZero(vector<int>&indegree,queue<int>&q){
        int n=indegree.size();
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        return;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       int e=edges.size();
       vector<vector<int>>adj(V);
       for(int i=0;i<e;i++){
           int u=edges[i][0];
           int v=edges[i][1];
           adj[u].push_back(v);
       }
       // found indegree of each node;
       vector<int>indegree(V,0);
       for(auto &it:adj){
          for(auto &neighboor:it){
              indegree[neighboor]++;
          }
       }
       vector<int>topo;
       queue<int>q;
       foundZero(indegree,q);
       while(!q.empty()){
          int temp=q.front();
          q.pop();
          topo.push_back(temp);
          for(int i=0;i<adj[temp].size();i++){
              int neighbor=adj[temp][i];
              indegree[neighbor]--;
              if(indegree[neighbor] == 0) {
                  q.push(neighbor);
              }
          }
       }
       return topo;
     
    }
};