#include<bits/stdc++.h>
using namespace std;

// using extra space.......
vector<vector<int>> reshape(vector<vector<int>>&m,int r,int c){
  //edge case
  if(r*c != m.size()*m[0].size()) return m;

  //matrix->array
   vector<int>m_array;
    for(int i=0;i<m.size();i++){
     for(int j=0;j<m[0].size();j++){
      m_array.push_back(m[i][j]);
     }
    }

   //array ->matrix
   vector<vector<int>>newm;
   int idx=0;
   for(int i=0;i<r;i++){
    vector<int>row;
   for(int j=0;j<c;j++){
     row.push_back(m_array[idx]);
     idx++;
    }
    newm.push_back(row) ;
}

   return newm;
}


// without using extra space.....

vector<vector<int>> dynamicReshape(vector<vector<int>>&m,int r,int c){
  //edge case
  if(r*c != m.size()*m[0].size()) return m;
  
  //new matrix direct from odl;
  vector<vector<int>>newm(r,vector<int>(c));
   int new_r=0,new_col=0;
   for(int i=0;i<m.size();i++){
    
     for(int j=0;j<m[0].size();j++){
         newm[new_r][new_col]=m[i][j];
         new_col++;
         if(new_col==c){
            new_col=0;
            new_r++;
         }
     }
   }
   return newm;
      
}

// without extra space but by use of mathmatical formula ----pending latter ---





void print(vector<vector<int>>&newm) {

     for(int i=0;i<newm.size();i++){
     for(int j=0;j<newm[0].size();j++){
         cout<<newm[i][j]<<" ";
     }
     cout<<endl;
    }
}


int main(){
    vector<vector<int>>m={
        {1,2,3,4},
        {5,6,7,8},
        {6,5,4,3},
    };
    cout<<"old : "<<endl;
    print(m);
    vector<vector<int>>newm= dynamicReshape(m,4,3);
    cout<<"new : "<<endl;
    print(newm);
}