#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
 for(int i=0,j=0;j<nums.size();j++){
    if(nums[j]!=0){
        swap(nums[i],nums[j]);
        i++;
    }
 }
}

// Helper function to print the array
void printArray(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Test Case 1
    vector<int> nums1 = {0,1,0,2,13};
    cout << "Original 1: "; printArray(nums1);
    moveZeroes(nums1);
    cout << "Modified 1: "; printArray(nums1);
    cout << "-------------------\n";

    // Test Case 2
    vector<int> nums2 = {0, 0, 0,1};
    cout << "Original 2: "; printArray(nums2);
    moveZeroes(nums2);
    cout << "Modified 2: "; printArray(nums2);
    cout << "-------------------\n";

    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    cout << "Original 3: "; printArray(nums3);
    moveZeroes(nums3);
    cout << "Modified 3: "; printArray(nums3);

    return 0;
}