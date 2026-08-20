#include<bits/stdc++.h>
using namespace std;

int countSubsequence(int i,int n,vector<int>&arr,int k,int sum){
 
    if(i==n){
        if(sum==k){
         return 1;
        }
        else return 0;
    }
    sum+=arr[i];
    int left=countSubsequence(i+1,n,arr,k,sum);

    sum-=arr[i];
    int right=countSubsequence(i+1,n,arr,k,sum);

    return left+right;
}


int main(){

  vector<int>arr={5,1};
  int k=5;
  cout<<countSubsequence(0,arr.size(),arr,k,0);
}