#include <bits/stdc++.h>
using namespace std;

// ---------------- BRUTE FORCE ----------------
int removeDuplicatesBrute(vector<int>& nums) {

    int n = nums.size();

    if(n==0) return 0;

    vector<int> ans;

    for(int i=0;i<n-1;i++){
        if(nums[i]!=nums[i+1]){
            ans.push_back(nums[i]);
        }
    }

    ans.push_back(nums[n-1]);

    for(int i=0;i<ans.size();i++){
        nums[i]=ans[i];
    }

    return ans.size();
}

// ---------------- BETTER ----------------
int removeDuplicatesBetter(vector<int>& nums) {
    
    // Write here

}

// ---------------- OPTIMAL ----------------
int removeDuplicatesOptimal(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    if(n==1) return 1;
    int l=0 ;
    for(int r=1;r<n;r++){
        if(nums[l]!=nums[r]){
            l++;
            nums[l]=nums[r];
        }
    }
    return l+1;

}

// ------------------------------------------
void printArray(const vector<int>& arr, int k) {

    k = min(k, (int)arr.size());

    cout << "[";

    for(int i=0;i<k;i++){
        cout << arr[i];
        if(i<k-1) cout << ", ";
    }

    cout << "]\n";
}

int main() {

    // Test Case 1
    vector<int> nums1 = {1,1,2,2,3,3,3,4};
    cout << "Original 1: ";
    printArray(nums1, nums1.size());

    int k1 = removeDuplicatesBrute(nums1);

    cout << "Unique 1 (k=" << k1 << "): ";
    printArray(nums1, k1);

    cout << "-------------------\n";

    // Test Case 2
    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    cout << "Original 2: ";
    printArray(nums2, nums2.size());

    int k2 = removeDuplicatesBetter(nums2);

    cout << "Unique 2 (k=" << k2 << "): ";
    printArray(nums2, k2);

    cout << "-------------------\n";

    // Test Case 3
    vector<int> nums3 = {1,1,1};
    cout << "Original 3: ";
    printArray(nums3, nums3.size());

    int k3 = removeDuplicatesOptimal(nums3);

    cout << "Unique 3 (k=" << k3 << "): ";
    printArray(nums3, k3);

    cout << "-------------------\n";

    // Test Case 4
    vector<int> nums4 = {};
    cout << "Original 4: ";
    printArray(nums4, nums4.size());

    int k4 = removeDuplicatesOptimal(nums4);

    cout << "Unique 4 (k=" << k4 << "): ";
    printArray(nums4, k4);

    cout << "-------------------\n";

    // Test Case 5
    vector<int> nums5 = {5};
    cout << "Original 5: ";
    printArray(nums5, nums5.size());

    int k5 = removeDuplicatesOptimal(nums5);

    cout << "Unique 5 (k=" << k5 << "): ";
    printArray(nums5, k5);

    return 0;
}