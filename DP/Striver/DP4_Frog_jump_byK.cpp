#include<bits/stdc++.h>
using namespace std;
int ByRec(int idx,vector<int>&h,int k){
    
    if(idx==0) return 0;
    int mini=INT_MAX;
    
    for(int i=1;i<=k;i++){
        if(idx-i>=0){
         int jump=(ByRec(idx-i,h,k)+abs(h[idx]-h[idx-i]));
         mini=min(mini,jump);
      }
  }
    return mini;
}

int ByRec2(int idx , vector<int>&h,vector<int>&dp,int k){
    
    if(idx==0) return 0;
    
    for(int i=1;i<=k;i++){
         int minii=INT_MAX;
         for(int j=1;j<=k;j++){
            if(i-j >=0){
            int jump=dp[i-j]+abs(h[idx]-h[idx-j]);
            minii=min(minii,jump);
         }
         dp[i]=minii;
        }
    }
    return dp[idx];
}
int main(){
    int idx=5;
    int k=3;
    vector<int>h={10,20,30,10,5,7};
    int t1=ByRec(idx,h,k);
    cout<<t1<<endl;

    vector<int>dp(idx+1,-1);
    int t2=ByRec2(idx,h,dp,k);
    cout<<t2<<endl;
    
}