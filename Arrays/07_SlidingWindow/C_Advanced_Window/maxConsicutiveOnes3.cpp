#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr,int k){
    int n=arr.size();
    int left=0,right=0;
    int maxi=0;
    int count0=0;
    int maa=0;
    stack<int>s;
    while(right<n){
        if(arr[right]==0) count0++;
        if(count0>k){
          if(arr[left]==0){
            count0--;
          }
          left++;
        }
        maxi=max(maxi,right-left+1);
        right++; 
    }
    return maxi;
}


int main(){
    int k=2;
    vector<int>arr={1,0,1,1,0,1,1};
    int maxi=fun(arr,k);
    cout<<maxi<<endl;
}
