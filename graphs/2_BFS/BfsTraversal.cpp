#include<bits/stdc++.h>
using namespace std;


// we move like corona virus spread..
// firstly one affected->select a node from where you want to start in graph
// use queue data structure ...push the neighboors of that node after poping node from queue and pused to ans

// making an Adjacency List
void make_al(int V,int E,vector<vector<int>>&al){
   for(int i=0;i<E;i++){
    int v,u;
    cin>>u>>v;
    al[u].push_back(v);
    al[v].push_back(u);
   }
   return ;
}

void printlist(int V,int E,vector<vector<int>>&al){
   
   for(int i=0;i<V;i++){
    cout<<i<<"->";
    for(int j=0;j<al[i].size();j++){
      cout<<al[i][j]<<" ";
    }
    cout<<endl;
   }
}
vector<int> bfs(int V,vector<vector<int>>&al){
   
  queue<int>q;
  q.push(0);
  vector<bool>visited(V,0);
  visited[0]=1;
  vector<int>ans;
  int node;
  while(!q.empty()){
    node=q.front();
    q.pop();
    ans.push_back(node);
    for(int i=0;i<al[node].size();i++){
      if(visited[al[node][i]]==0){
       q.push(al[node][i]);
       visited[al[node][i]]=1;
      }
    }
  }
  return ans;
}
int main(){
  int V,E;
  cin>>V>>E;
  vector<vector<int>>al(V); //al=Adjacency List
  make_al(V,E,al);
  printlist(V,E,al);

  vector<int> answer=bfs(V,al);
  for(const auto x:answer){
    cout<<x<<" ";
  }
  cout<<endl;


  return 0;
}