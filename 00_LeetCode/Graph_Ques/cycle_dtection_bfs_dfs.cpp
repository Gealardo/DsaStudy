#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
   // using dfs mathod
    bool founded(int node,int parent,vector<vector<int>>&edges,vector<int>&visited){
           visited[node]=1;
           for(auto &it :edges[node]){
                 if(!visited[it]){
                     if(founded(it,node,edges,visited)) return true;
                 }
                 else if(it!=parent) return true;
           }
           return false;
    }
    //using bfs ...
     bool founded2(int start,vector<vector<int>>&edges,vector<int>&visited){
        queue<pair<int,int>>q;
        q.push({start,-1});
        visited[start]=1;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto& neighboor:edges[node]){
                if(!visited[neighboor]){
                    q.push({neighboor,node});
                    visited[neighboor]=1;
                }
                else{
                   if(neighboor!=parent) return true; 
                } 
            }
        }
      return false;
    }
   
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto & it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
       vector<int>visited(V,0);
       for(int i=0;i<V;i++){
           if(!visited[i]){
               if(founded(i,-1,adj,visited)==true) return true;
           }
       }
      return false;  
    }
};

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
    }

    Solution obj;

    if (obj.isCycle(V, edges))
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle is NOT present" << endl;

    
}