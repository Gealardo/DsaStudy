#include<bits/stdc++.h>
using namespace std;

void fun(int idx,vector<int>&arr,vector<int>&ans,int k,int sum){
   
    // base case printing at last time..
    if(idx==arr.size()){
        if(sum==k){
            for(auto x:ans){
                cout<<x<<" ";
            }
            cout<<endl;
          
        }
          return;
    }
       //pick 
       ans.push_back(arr[idx]);
       sum+=arr[idx];
       fun(idx+1,arr,ans,k,sum);

       //back track
       ans.pop_back();
       sum-=arr[idx];
       
       //not pick
       fun(idx+1,arr,ans,k,sum);
   
}

int main(){
    vector<int>arr={1,6,3,4};
    vector<int>ans;
    int k=10;
    fun(0,arr,ans,k,0);

}