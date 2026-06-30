#include<bits/stdc++.h>
using namespace std;
// Detection of Cycle in undirected no-weight graph by Dfs via recurtion
bool cycleDetection(int node,int parent, const vector<vector<int>>&adj,vector<int>&visited){

  visited[node]=1;
  for(int j=0;j<adj[node].size();j++){

    //parent ingnore
    if(parent==adj[node][j]) continue;
    
    //visited ->cycle detected
    if(visited[adj[node][j]]==1) return true;

    //continue for next recursively
    if (cycleDetection(adj[node][j],node,adj,visited)) return 1;
  }
  
  return false;
}

//make adj list
void makelist(int V,int E, vector<vector<int>>&adj){
    for(int i=0;i<E;i++){
       int v,u;
       cin>>v>>u;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
}
//print adjlist
void printadj(int V,int E,const vector<vector<int>>&adj){
  for(int i=0;i<V;i++){
    cout<<i<<"->";
    for(int j=0;j<adj[i].size();j++){
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main(){
  int V,E;
  cin>>V>>E;
  vector<vector<int>>adj(V);
  makelist(V,E,adj);
  printadj(V,E,adj);
  vector<int>visited(V);



  for(int i=0;i<V;i++){
    if(visited[i]!=1){

     if (cycleDetection(i, -1, adj, visited)) {
              true;
              break;
            }
     }
}  

  return 0;
}

// what if graph is disconected ->for loop calling inside main()
