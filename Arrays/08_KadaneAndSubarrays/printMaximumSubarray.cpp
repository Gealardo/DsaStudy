#include<bits/stdc++.h>
using namespace std;
 int maxSum=INT_MIN;
// LeetCode 53: Maximum Subarray
pair<int,int> maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int startans=0;
    int endans=0;
   
    int currsum=0;
    int start=0;
    for(int i=0;i<nums.size();i++){
        currsum+=nums[i];
        if(currsum>maxSum){
             endans=i;
             startans=start;
    
    }
        maxSum=max(currsum,maxSum);
        
        if(currsum<0){
            currsum=0;
            if(i+1<n) start=i+1;
        }
       
    }
    
    
    
 return {startans,endans};
}
void maxSubfun(vector<int>&nums){
    int maxx=nums[0];
    int startans=0;
    int endans=0;
    int maxsum=nums[0];
    int start=0;
    for(int i=1;i<nums.size();i++){
        maxx=max(nums[i],maxx+nums[i]);
        if(maxx==maxx+nums[i]){
            startans=start;
            endans=i;
        }
        maxsum=max(maxx,maxsum);
    }
}
int main(){
    vector<int> nums = {-3, 5, 2, -9};
    pair<int,int> ans = maxSubArray(nums);
    
    cout << "Max Sum: " <<maxSum << endl;
    cout << "Subarray: [";
    for(int i = ans.first; i <= ans.second; i++){
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
    
    return 0;
}
