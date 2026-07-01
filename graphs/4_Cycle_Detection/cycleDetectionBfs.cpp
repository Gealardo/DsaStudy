#include<bits/stdc++.h>
using namespace std;

//cycle detection by Bfs
bool isCycle(int node,int parent,const vector<vector<int>>&adj,vector<int>&visited){
  visited[node]=1;
  queue<pair<int,int>>q;
  q.push(make_pair(node,parent));
  while(!q.empty()){
    pair<int,int>curr=q.front();
    q.pop();
    for(int j=0;j<adj[curr.first].size();j++){
       //node is parent
       if(adj[curr.first][j]==curr.second) continue;
       //node already visited
       if(visited[adj[curr.first][j]]==1) return true;
        
       visited[adj[curr.first][j]] = 1;
       q.push({adj[curr.first][j], curr.first});
  }
 
   }
     return false;
}
//make the adj (Adjancey List)
void makeadj( int V,int E,vector<vector<int>>&adj){
  for(int i=0;i<E;i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
     adj[v].push_back(u);
  }
}
//print adj
void printlist(int V,int E,const vector<vector<int>>&adj){
  cout<<"-------AdjanceyList---------"<<endl;
  for(int i=0;i<V;i++){
    cout<<i<<"-->";
    for(int j=0;j<adj[i].size();j++){
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }

}
//main funtion ->handle disconected graph as well
int main(){
 int V,E; cin>>V>>E;
 vector<vector<int>>adj(V);
 makeadj(V,E,adj);

 printlist(V,E,adj);
 bool cycle=false;
 vector<int>visited(V);
 for(int i=0;i<V;i++){
  if(!visited[i] && isCycle(i,-1,adj,visited) ){
     cycle= true;
      break;
  }
 }
 if(cycle ==true) cout<<"Cycle Detected"<<endl;

}