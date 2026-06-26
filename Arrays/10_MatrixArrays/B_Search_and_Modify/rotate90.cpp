#include<bits/stdc++.h>
using namespace std;

void rorate(vector<vector<int>>&m){
    int r=m.size();
    int c=m[0].size();
   // rotate 90 ==> transpose+reverse row; 
   //transpose
   for(int i=0;i<r;i++){
     for(int j=i+1;j<c;j++){
       swap(m[i][j],m[j][i]);
     }
   }
   //reverse row
   for(int i=0;i<r;i++){
     int l=0;
     int ri=c-1;
     while(l<ri){
        swap(m[i][l],m[i][ri]);
        ri--;
        l++;
     }
   }
}



int main(){
  vector<vector<int>>m={

    {1,2,3},
    {4,5,6},
    {7,8,9},
  };
  rorate(m);
  int r=m.size();
    int c=m[0].size();
  for(int i=0;i<r;i++){
     for(int j=0;j<c;j++){
       cout<<m[i][j]<<" ";

        }
        cout<<endl;
    }
}