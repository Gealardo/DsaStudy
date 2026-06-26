#include<bits/stdc++.h>
using namespace std;

int countSubarraySumisK(vector<int>&arr,int k){
    int count=0;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
              sum+=arr[j];
              if(sum==k) count++;
        }
    }
    return count;
}
//optimal only if array contains only positives...wrong---
int fun(vector<int>&arr,int k){
    int n=arr.size();
    int left=0,right=0;
    int count=0;
    int sum=0;
    while(right<n){
         sum+=arr[right];

         while(sum==k){
            count++;
            // remove left
            sum-=arr[left];
            left++;
         }
         right++;
    }
    return count;
}


int main(){
    vector<int>arr={1,1,9,2,7};
    int k=2;
    int c=countSubarraySumisK(arr,k);
    cout<<c<<endl;
    int cc=fun(arr,k);
    cout<<cc<<endl;
}