/*
Question

Every number appears twice.

Only one appears once.

Find it.

Example
     2 2 1

     Answer

     1

*/
#include<bits/stdc++.h>
using namespace std;

int unique(const vector<int>& nums){

  int n=nums.size();

  if(n==0) return -1;

  int unique=0;

  for(int i=0; i<n;i++){
      unique^=nums[i];
  }

 return unique;
}

int main(){
  vector<int>nums={1,1,0,3,3};

  int ans=unique(nums);
  cout<<ans<<endl;

  return 0;
}