//----------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;





vector<int> diagonal(vector<vector<int>>&m){
    
       vector<int>ans;
       if(m.empty()) return ans;
       int r=0;
       int c=0;
       int n=m.size()*m[0].size();

       for(int i=0;i<n;i++){
          int sum=r+c;

          ans.push_back(m[r][c]);

          if(sum%2==0){
            // up-> right
          
            if(c==m[0].size()-1){
               //right wall hit
               r++;
            }
            else if(r==0){
               //up wall hit move right
               c++; 
            }
            
            else{
                //normal
                r--;
                c++;
            }
          }

          if(sum%2!=0){
            //down ->left
            if(r==m.size()-1){
            //bottom hit
              c++;
            }
            else if(c==0){
            //left hit
            r++;
            }
            else{
                //normal
                r++;
                c--;
            }
          }

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

   vector<int> diagonalAns=diagonal(m);
   for( auto x:diagonalAns){
      cout<<x<<" ";
   }
   cout<<endl;

}