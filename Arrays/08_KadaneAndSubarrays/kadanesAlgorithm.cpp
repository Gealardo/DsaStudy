#include<bits/stdc++.h>
using namespace std;
//brute for subarray represent all O(n^3)
int pritAll(vector<int>nums){
    for(int i=0;i<nums.size();i++){

        for(int j=i;j<nums.size();j++){
               cout<<"[";
            for(int k=i;k<=j;k++){
                  cout<<nums[k]<<" ";
            }
            cout<<"]";
        }
    }
}
//brute for subarray represent all sums O(n^2)
vector<int> sumofALL(vector<int>nums){
    vector<int>s;
    for(int i=0;i<nums.size();i++){
       int  sum=0;
        for(int j=i;j<nums.size();j++){
          sum+=nums[j];
          s.push_back(sum);
        }
    }
    return s;
}
//brute for subarray max of all O(n^2)
int maxofALL(vector<int>nums){
    int max_sum=0;
    for(int i=0;i<nums.size();i++){
       int  sum=0;
        for(int j=i;j<nums.size();j++){
          sum+=nums[j];
          max_sum=max(max_sum,sum);
        }
    }
    return max_sum;
}

//brute for subarray max of all subbarray sum O(n) optimal;
// LeetCode 53: Maximum Subarray
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum=INT_MIN;
    int currsum=0;
    for(int i=0;i<nums.size();i++){
        currsum+=nums[i];
        maxSum=max(currsum,maxSum);
        if(currsum<0){
            currsum=0;
        }
       
    }
    
    
 return maxSum;
}

int main() {
    // Test Case 1: Standard mixed array
    vector<int> nums1 = {-2, 1, -3, 4};
    cout<< pritAll(nums1) << endl;
    cout<<endl;
    vector<int>sum=sumofALL(nums1);
    for(const auto i:sum){
        cout<<i<<" ";
    }
    cout<<endl;
    int maxi=maxofALL(nums1);
    cout<<maxi<<endl;

    // Test Case 2: All negative numbers (Edge Case!)
    vector<int> nums2 = {-3, -5, -2, -9};
    cout << "Test 2: " << maxSubArray(nums2) << " (Expected: -2)\n";
    // Subarray: [-2]

    // Test Case 3: All positive numbers
    vector<int> nums3 = {1, 2, 3, 4};
    cout << "Test 3: " << maxSubArray(nums3) << " (Expected: 10)\n";

    return 0;
}