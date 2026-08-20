#include<bits/stdc++.h>
using namespace std;

// (2^n)*n->tc ....O(n)->space;
void subsequence(int i,int n,vector<int>arr,vector<int>ans){
   
  //base case
  if(i>=n){
    if(ans.empty()) cout<<"[]";
    for(const auto x:ans){
      cout<<x<<" ";
    }
    cout<<endl;
    return;
  }
  //pick
  ans.push_back(arr[i]);
  subsequence(i+1,n,arr,ans);

  //not pick
  ans.pop_back();
  subsequence(i+1,n,arr,ans);

}

void subsequenceSumEqualK(int i,int n,vector<int>&arr,int sum,int k){
  
  if(i>=n){
         if(sum==k){
          cout<<"true"<<endl;
         }
          return;
   }
   
   sum+=arr[i];
   subsequenceSumEqualK(i+1,n,arr,sum,k);
   sum-=arr[i];
   subsequenceSumEqualK(i+1,n,arr,sum,k);
  
 
}

//modified version of subsequenceSumEqualK to return boolean value and check just one time if sum==k and return true or false
bool subsequenceSumEqualK2(int i,int n,vector<int>&arr,int sum,int k){ 
  if(i>=n){
         if(sum==k){
          return true;
         }
         else  return false;
   }  
   sum+=arr[i];
   if(subsequenceSumEqualK2(i+1,n,arr,sum,k) ==true) return true;
   sum-=arr[i];
   if(subsequenceSumEqualK2(i+1,n,arr,sum,k)==true) return true;
}

int main(){
  vector<int>arr={1,8,7,4,2};
  vector<int>ans;
  subsequence(0,arr.size(),arr,ans);

  cout<<"subsequence sum 7 exist? :";
  subsequenceSumEqualK(0,arr.size(),arr,0,7);
  cout<<"\nsubsequence sum 7 exist? :";
  cout<< subsequenceSumEqualK2(0,arr.size(),arr,0,7)<<endl;

}