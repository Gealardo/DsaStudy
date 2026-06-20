#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr){
    int n=arr.size();
    int r=0;
    int maxi=0;
    int maxx=0;
    while(r<n){
       if(arr[r]!=1){
        maxx=0;
        r++;
    }
       else{
         maxx++;
         maxi=max(maxx,maxi);
         r++;
       }
       
   }
   return maxi;
}


int main(){
    int target=3;
    vector<int>arr={0,0,2,2,2,1,1};
    int maxi=fun(arr);
    cout<<maxi<<endl;
}
