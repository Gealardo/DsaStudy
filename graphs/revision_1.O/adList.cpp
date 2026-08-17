#include<bits/stdc++.h>
using namespace std;

void makegraph(vector<vector<int>>&graph,int v){
 int e;
 cout<<"enter no. of edges: ";
 cin>>e;
 for(int i=0;i<e;i++){
   int a,b;
   cin>>a>>b;
   if(a>v-1 || b>v-1 || a<0 ||b<0){
    cout<<"vertex Not exist "<<endl;
    continue;
   }
   else{
   graph[a].push_back(b);
   graph[b].push_back(a);
   }
 }
}
void print(vector<vector<int>>&graph){
  int i=0;
  for(const auto &row : graph){
    cout<<i++<<" -> ";
    for(const auto col : row){

      cout<<col<<" ";
      
    }
    cout<<endl;
  }
  cout<<endl;
}



int main(){
int v;
cout<<"enter no. of vertex: ";
cin>>v;
vector<vector<int>>graph(v);
makegraph(graph,v);
cout<<"Adjec List"<<endl;
print(graph);
}