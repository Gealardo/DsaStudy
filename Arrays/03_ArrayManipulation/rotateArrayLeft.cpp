#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int>&nums,int low,int k){
    int high=k-1;
    while(low<high){
        swap(nums[low],nums[high]);
        low++;high--;
    }

}

void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k=k%n;
    reverse(nums,0,k);
    reverse(nums,k,nums.size());
    reverse(nums,0,nums.size());
   
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

    // Test Case 1: Standard rotation
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    cout << "Original 1: "; printArray(nums1);
    rotate(nums1, k1);
    cout << "Left Rotated 1 (k=" << k1 << "): "; printArray(nums1);
    cout << "-------------------\n";

    // Test Case 2: k is larger than array size (The Trap!)
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2; // Wait, what if k was 6? 6 % 4 = 2. Same result!
    cout << "Lest Original 2: "; printArray(nums2);
    rotate(nums2, k2);
    cout << "Lest Rotated 2 (k=" << k2 << "): "; printArray(nums2);
    cout << "-------------------\n";

    // Test Case 3: Single element
    vector<int> nums3 = {1};
    int k3 = 2;
    cout << "Original 3: "; printArray(nums3);
    rotate(nums3, k3);
    cout << "Lesft Rotated 3 (k=" << k3 << "): "; printArray(nums3);

    return 0;
}