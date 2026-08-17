#include<bits/stdc++.h>
using namespace std;

void makelist(vector<vector<int>>&l,int v){
  int e;
  cout<<"E: ";
  cin>>e;
  for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    l[a].push_back(b);
    l[b].push_back(a);
  }
}

vector<int> bfs(vector<vector<int>>&l,vector<bool>&visited,int start_node){
    vector<int>bfsAns;
    queue<int>q;

    q.push(start_node); 
    visited[start_node]=true;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfsAns.push_back(node);

        for(int i=0;i<l[node].size();i++){
          if(visited[l[node][i]]!=true){
            q.push(l[node][i]);
             visited[l[node][i]]=true;
          }
        }
    }   
   return bfsAns;
}


vector<int> dfs(vector<vector<int>>&l,vector<bool>&visited2,int start_node){
    vector<int>dfsAns;
    stack<int>s;
    s.push(start_node); 
  
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(visited2[node]) continue;

        visited2[node] = true;
        dfsAns.push_back(node);

        for(auto neighboor:l[node]){
          if(!visited2[neighboor]){
            s.push(neighboor);
          }
        }  
    }   
   return dfsAns;
}

void dfsrec(vector<vector<int>>&l,vector<bool>&visited3,vector<int>&dfsansrec,int node){

   visited3[node]=true;
   dfsansrec.push_back(node);

   for(auto neighboor: l[node]){
    if(visited3[neighboor]!=true){
      dfsrec(l,visited3,dfsansrec,neighboor);
    }
   }

}

int main(){

  int v;
  cout<<"v: ";
  cin>>v;
  vector<vector<int>>l(v);
  makelist(l,v);

  vector<bool>visited(v,false);
  vector<bool>visited2(v,false);
  
  int start_node=0;

  cout<<"bfs traversal :"<<endl;
  vector<int>ans=bfs(l,visited,start_node);
  for(const auto i:ans){
    cout<<i<<" ";
  }
  cout<<endl;

  cout<<"dfs traversal :"<<endl;
  vector<int>ans2=dfs(l,visited2,start_node);
  for(const auto i:ans2){
    cout<<i<<" ";
  }
  cout<<endl;


  cout<<"dfs traversal rec :"<<endl;
  vector<int>dfsansrec;
  vector<bool>visited3(v,false);
  for(int i=0;i<v;i++){
     if(!visited3[i]){
        dfsrec(l,visited3,dfsansrec,i);
     }
  }
  for(const auto &i:dfsansrec){
    cout<<i<<" ";
  }
  cout<<endl;

 return 0;

}