#include<bits/stdc++.h>
using namespace std;

vector<int> boundries(vector<vector<int>>&m){
    vector<int>ans;
    int top=0;
    int right=m[0].size()-1;
    int left=0;
    int bottom=m.size()-1;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(m[top][i]);
         
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(m[i][right]);
        }
        right--;
        if( top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(m[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                  ans.push_back(m[i][left]);
            }
        }
        break;
    }
    return ans;
}




int main(){

   vector<vector<int>>m={
     
      
      {5,6,7},
      {1,2,3},
      {8,9,0}
    

   };

   vector<int> ans=boundries(m);
   for( auto x:ans){
      cout<<x<<" ";
   }
   cout<<endl;

}