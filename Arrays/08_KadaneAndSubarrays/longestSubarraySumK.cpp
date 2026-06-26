#include<bits/stdc++.h>
using namespace std;

// Version 1: Brute Force - O(N³)
int longestSubarrayBrute(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    for(int i=0;i<n;i++){
       
        for(int j=i;j<n;j++){
             int sum=0;
             for(int idx=i;idx<=j;idx++){
                sum+=arr[idx];
                }
                if(sum==k){
                    int len=(j-i+1);
                    maxLen=max(maxLen,len);
                }
             }
        }

         return maxLen;
}
    
   

// Version 2: Better - O(N²)
int longestSubarrayBetter(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    for(int i=0;i<n;i++){
          int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                int len=j-i+1;
                maxLen=max(maxLen,len);
            }
        }

        
}
 return maxLen;
}

// Version 3: Optimal - O(N)
int longestSubarrayOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    int prefixsum =0;
    unordered_map<int, int> sumIndex; 
    for(int i=0;i<n;i++){
        prefixsum=prefixsum+arr[i];
        sumIndex[prefixsum]=i;
        if(prefixsum == k){
          maxLen = i + 1;
        }
       int rem = prefixsum - k;  
       if(sumIndex.count(rem)){  
        maxLen = max(maxLen, i - sumIndex[rem]); 
       }
    }

    return maxLen;
}

int main() {
    // Test Case 1
    vector<int> arr1 = {2, 3, 5, 1, 9};
    int k1 = 10;
    cout << "Test 1 Brute: " << longestSubarrayBrute(arr1, k1) << " (Expected: 3)\n";
    cout << "Test 1 Better: " << longestSubarrayBetter(arr1, k1) << " (Expected: 3)\n";
    cout << "Test 1 Optimal: " << longestSubarrayOptimal(arr1, k1) << " (Expected: 3)\n\n";
    
    // Test Case 2
    vector<int> arr2 = {1, 2, 3, -3, 1, 2};
    int k2 = 3;
    cout << "Test 2 Brute: " << longestSubarrayBrute(arr2, k2) << " (Expected: 4)\n";
    cout << "Test 2 Better: " << longestSubarrayBetter(arr2, k2) << " (Expected: 4)\n";
    cout << "Test 2 Optimal: " << longestSubarrayOptimal(arr2, k2) << " (Expected: 4)\n\n";
    
    // Test Case 3 (Edge Case)
    vector<int> arr3 = {-5, -2, -3, 8};
    int k3 = -5;
    cout << "Test 3 Brute: " << longestSubarrayBrute(arr3, k3) << " (Expected: 2)\n";
    cout << "Test 3 Better: " << longestSubarrayBetter(arr3, k3) << " (Expected: 2)\n";
    cout << "Test 3 Optimal: " << longestSubarrayOptimal(arr3, k3) << " (Expected: 2)\n";
    
    return 0;
}