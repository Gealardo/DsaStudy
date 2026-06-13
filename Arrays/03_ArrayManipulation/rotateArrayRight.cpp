#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& nums, int low, int high){
    high--; // Convert size to index
    while(low < high){
        swap(nums[low], nums[high]);
        low++; 
        high--;
    }
}

void rotateRight(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    // reverse(nums,0,n-k);
    // reverse(nums,n-k,nums.size());
    // reverse(nums,0,nums.size());  
   
    reverse(nums, 0, n);      // 1. Reverse entire array
    reverse(nums, 0, k);      // 2. Reverse first k elements
    reverse(nums, k, n);      // 3. Reverse remaining n-k elements
}

void printArray(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Test Case 1: Standard rotation
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    cout << "Original 1: "; printArray(nums1);
    rotateRight(nums1, k1);
    cout << "Right Rotated 1 (k=" << k1 << "): "; printArray(nums1);
    cout << "-------------------\n";

    // Test Case 2: k is larger than array size (The Trap!)
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    cout << "Original 2: "; printArray(nums2);
    rotateRight(nums2, k2);
    cout << "Right Rotated 2 (k=" << k2 << "): "; printArray(nums2);
    cout << "-------------------\n";

    // Test Case 3: Single element
    vector<int> nums3 = {1};
    int k3 = 2;
    cout << "Original 3: "; printArray(nums3);
    rotateRight(nums3, k3);
    cout << "Right Rotated 3 (k=" << k3 << "): "; printArray(nums3);

    return 0;
}