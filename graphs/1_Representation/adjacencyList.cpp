#include<bits/stdc++.h>
using namespace std;
int main(){
// undirected,weight.
  int V,E;
  cin>>V>>E;
  cout<<"Enter edges : ";
  vector<pair<int,int>> AdjList[V];
  for(int i=0;i<E;i++){
    int u,v,weight; cin>>u>>v>>weight;
    AdjList[u].push_back(make_pair(v,weight));
     AdjList[v].push_back(make_pair(u,weight));//remove for directed
  }

  // print

  for(int i=0;i<V;i++){
    cout<<i<<"->";
    for(int j=0;j<AdjList[i].size();j++){
      cout<<AdjList[i][j].first<<" ";
       cout<<AdjList[i][j].second<<" ";
    }
    cout<<endl;
  }
}