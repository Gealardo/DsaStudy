#include<bits/stdc++.h>
using namespace std;


void makeadjency(vector<vector<int>>&m,int v,int e){

   for(int i=0;i<e;i++){

          int a,b; /// a---b;         
          cin>>a>>b;
     
          if(a>v-1 || b>v-1 || a<0 || b<0) {
             cout<<"vertex not exist in graph"<<endl;
             continue;
          }
        // if a==b self loop detected // allowed for now
          else { 
              m[a][b]=1;
              m[b][a]=1;
          }
   }
}

void print(vector<vector<int>>&m){

  for(const auto &row : m){

    for(const auto col : row){

      cout<<col<<" ";
      
    }
    cout<<endl;
  }
  cout<<endl;
}


int main(){

   int v,e;
   cout<<"enter no. of vectex: ";
   cin>>v;
   cout<<"enter no. of edge: ";
   cin>>e;
   vector<vector<int>>m(v,vector<int>(v,0));
   
   makeadjency(m,v,e);
   cout<<"Adjecency Matrix"<<endl;
   print(m);
}





