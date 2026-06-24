/*

Top Row: Go Left ️ Right. Then, top++ (we finished the top row, shrink the box down).
Right Col: Go Top ️ Bottom. Then, right-- (shrink box left).
Bottom Row: Go Right to Left. Then, bottom-- (shrink box up).
Left Col: Go Bottom to Top. Then, left++ (shrink box right).

*/
//----------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;


vector<int> spiralTraversal(vector<vector<int>>&m){
       vector<int>ans;
       int top=0;
       int right=m[0].size()-1;
       int bottom=m.size()-1;
       int left=0;

       while(top<=bottom && left<=right){

         //top left->right
         for(int i=left;i<=right;i++){
           ans.push_back(m[top][i]);
         }
         top++;
         //right top->bottom
         for(int i=top;i<=bottom;i++){
            ans.push_back(m[i][right]);
         }
         right--;
         //bottom right->left
         if(top<=bottom){
            for(int i=right;i>=left;i--){
              ans.push_back(m[bottom][i]);
            }
            bottom--;
         }
         //left bottom->top
         if(left<=right){
            for(int i=bottom;i>=top;i--){
              ans.push_back(m[i][left]);
            }
         }
         left++;
       }

       return ans;

}

int main(){

   vector<vector<int>>m={
     
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12},
      {13,14,15,16}

   };

   vector<int> spiralAns=spiralTraversal(m);
   for( auto x:spiralAns){
      cout<<x<<" ";
   }
   cout<<endl;

}