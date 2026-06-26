#include<bits/stdc++.h>
using namespace std;
 
int maxProduct(vector<int>nums){
    int maxpro=nums[0];
    int minpro=nums[0];
    int result=nums[0];
    for(int i=1;i<nums.size();i++){
         if(nums[i]<0){
            swap(minpro,maxpro);
         }
         minpro=min(nums[i],minpro*nums[i]);
         maxpro=max(nums[i],maxpro*nums[i]);

         result=max(result,maxpro);
    }

   return result;
    
    }
 

int main(){
    vector<int> nums = {-3, -5, -2, 9};
    
     int x=maxProduct(nums);
     cout<<x<<endl;
   
    
    return 0;
}