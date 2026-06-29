/*
k numbers repeating and only one will be alone/unique.
example -> Q: [1,1,1,2,3,2,5,2,3,3] here k=3. 
           Ans: 5.

*/
#include<bits/stdc++.h>
using namespace std;

int unique(const vector<int>& nums,int k){
  int result=0;
  int n=nums.size();

  if(n==0) return -1;
  
  for(int i=0;i<=31;i++){
   int  count=0;
    for(int j=0;j<n;j++){
      if((nums[j]>>i)&1 ==1){
        count++;
      }
    }

    if(count%k!=0){
       result=result|(1<<i);
    }

   
  }


 return result;
}

int main(){
  vector<int>nums={1,1,1,1,2,2,2,3,4,2,3,3,3};
  int k=4;
  int ans=unique(nums,k);
  cout<<ans<<endl;

  return 0;
}