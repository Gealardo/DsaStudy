#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> fun(vector<vector<int>>&a,vector<vector<int>>&b){
    if(a.empty()|| b.empty()) return {};
      if(a.size()!=b.size() ||a[0].size()!=b[0].size() ) return {};

      int row=a.size(),col=a[0].size();

      vector<vector<int>>c(row,vector<int>(col,0));

      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
      }
      return c;
     
}
void printMatrix(const vector<vector<int>>& mat) {
    for(auto row : mat) {
        for(int x : row) cout << x << " ";
        cout << endl;
    }
}

int main(){
     vector<vector<int>> a = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    vector<vector<int>> b = {
        {1, 2, 3},
        {3, 4, 5},
    };
    vector<vector<int>>ans=fun(a,b);
    printMatrix(ans);
    
}