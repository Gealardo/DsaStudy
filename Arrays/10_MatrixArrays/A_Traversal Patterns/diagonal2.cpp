#include<bits/stdc++.h>
using namespace std;

vector<int> fun(vector <vector<int>>m){
    vector<int>ans;
      if(m.empty()) return ans;

      int r=0;
      int c=m[0].size()-1;

      int n=m.size()*m[0].size();
      for(int i=0;i<n;i++){
        ans.push_back(m[r][c]);
        if(i==n-1) break;
        int sum=r+c;

        //if sum is even
        if(sum%2==0){
           //left->up 
           if(c==0){
            r++;
           }
           else if(r==0){
             c--;
           }
           else{
             r--;
             c--;
           }

        }
               
        //if sum is odd
        //down->right
        if(sum%2!=0){
            // down right
            if(r==m.size()-1){
                c--;
            }
            else if(c==m[0].size()-1){
                r++;
            }
            else{
                r++;
                c++;
            }
        }

      }
      return ans;
}
int main(){
    vector<vector<int>>m={

        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int>dia=fun(m);
    for(auto x:dia){
        cout<<x<<" ";
    }
    cout<<endl;
}