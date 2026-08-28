#include<bits/stdc++.h>
using namespace std;
class Solution {
     //topological sort->
        /*
        adj list
        take a stack push node during dfs
        return stack element in reverse order
        */
  public:
   void dfs(int node,vector<vector<int>>&adj,vector<int>&visited,stack<int>&st){
       visited[node]=1;
       for(auto &it:adj[node]){
           if(!visited[it]) dfs(it,adj,visited,st);
       }
       st.push(node);
   }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       int e=edges.size();
       vector<vector<int>>adj(V);
       for(int i=0;i<e;i++){
           int u=edges[i][0];
           int v=edges[i][1];
           adj[u].push_back(v);
       }
       stack<int>st;
       vector<int>visited(V,0);
       for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(i,adj,visited,st);
           }
       }
       vector<int>topo;
       while(!st.empty()){
           topo.push_back(st.top());
           st.pop();
       }
       return topo;
    }
};