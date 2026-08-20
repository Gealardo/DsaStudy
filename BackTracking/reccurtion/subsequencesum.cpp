#include<bits/stdc++.h>
using namespace std;

void countSubsequence(int i,int n,vector<int>&arr,vector<int>&ds,int k){
 
    if(i>=n){
      int sum=0;
      for(auto x:ds){
        sum+=x;
      }
      cout<<sum;
      if(sum==k) cout<<" ->Found Target";
      cout<<endl;
      return;
    }
    ds.push_back(arr[i]);
    countSubsequence(i+1,n,arr,ds,k);

    ds.pop_back();
    countSubsequence(i+1,n,arr,ds,k);
}

void sum1(int j,int n,vector<int>&arr,vector<int>&ds2,int k,int sum){
    if(sum>k){
      return;  
    }
    if(sum==k){
      for(auto x:ds2){
        cout<<x<<" ";
      }
      cout<<endl;
      return;
    }
    if(j>=n){
      return;
    }

    sum+=arr[j];
    ds2.push_back(arr[j]);
    sum1(j+1,n,arr,ds2,k,sum);

    sum-=arr[j];
    ds2.pop_back();
    while(j+1<n && arr[j]==arr[j+1]) j++;
    sum1(j+1,n,arr,ds2,k,sum);
}

int main(){

  vector<int>arr={5,1,2,6,1,9,8};
  vector<int>ds;
  countSubsequence(0,arr.size(),arr,ds,9);
  cout<<endl<<endl;
  vector<int>ds2;
  sort(arr.begin(),arr.end());
  sum1(0,arr.size(),arr,ds2,9,0);
}