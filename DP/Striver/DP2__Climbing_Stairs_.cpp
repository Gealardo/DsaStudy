#include<bits/stdc++.h>
using namespace std;
// n->stair where to reach ->ways(n-1)+ways(n-2);
int waysRecursive(int n){
    if(n<2){
        return 1;
    }
    return waysRecursive(n-1)+waysRecursive(n-2);
}
// recursive+ memo
int waysRecursive2(int n,vector<int>&dp){
    if(n<2){
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    return dp[n]=waysRecursive2(n-1,dp)+waysRecursive2(n-2,dp);
}

int waysTabular(int n,vector<int>&ways){

     if(n<2){
        return 1;
     }
     ways[0]=1;
     ways[1]=1;
    
     for(int i=2;i<=n;i++){
        ways[i]=ways[i-1]+ways[i-2];
     }
     return ways[n];
}



int waysOptimal(int n)
{
    if(n < 2)
        return 1;

    int prev2 = 1;
    int prev1 = 1;

    for(int i=2;i<=n;i++)
    {
        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
   int n=4;
   int t1=waysRecursive(n);
   cout<<t1<<endl;

   vector<int>dp(n+1,-1);
   int t2=waysRecursive2(n,dp);
   cout<<t2<<endl;

   vector<int>ways(n+1,-1);
   int t3=waysTabular(n,ways);
   cout<<t3<<endl;


   int t4=waysOptimal(n);
   cout<<t4<<endl;

}