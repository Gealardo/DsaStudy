#include<bits/stdc++.h>
using namespace std; 

int maxS(vector<int>nums){
    int maxs=INT_MIN;
    int currsum=0;
    for(int i=0;i<nums.size();i++){
          currsum+=nums[i];
          maxs=max(maxs,currsum);

          if(currsum<0){
            currsum=0;
          }
    }
    return  maxs;
}
int minS(vector<int>nums){
    int mins=INT_MAX;
    int currsum=0;
    for(int i=0;i<nums.size();i++){
          currsum+=nums[i];
          mins=min(mins,currsum);

          if(currsum>0){
            currsum=0;  
          }
    }
    return mins;
}
int maxSum(vector<int>nums){
    //maxsum>0 totalsum-minsum of subarray
    //maxsum<0 maxsum.
    int totalsum=0;
    for(auto i: nums) totalsum+=i;
    int maxsum=maxS(nums);
    int minsum=minS(nums);
     
    if(maxsum<0) return maxsum;
    else return max(maxsum,totalsum-minsum); 

}
 

int main(){
    vector<int> nums = {3, -5, -2, 9};
    
     int x=maxSum(nums);
     cout<<x<<endl;
   
    
    return 0;
}