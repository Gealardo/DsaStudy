#include <bits/stdc++.h>
using namespace std;

 int removeDuplicates(vector<int>& nums){
  if(nums.size()==0) return 0;
   int i=0;
   for(int j=1;j<nums.size();j++){
     if(nums[i]!=nums[j]){
        i++;
        nums[i]=nums[j];
     }
   }
   return i+1;
 }

void printArray(const vector<int>& arr, int k) {
    cout << "[";
    for (int i = 0; i < k; i++) {
        cout << arr[i];
        if (i < k - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums1 = {1,2,3};
    cout << "Original 1: "; printArray(nums1, nums1.size());
    int k1 = removeDuplicates(nums1);
    cout << "Unique 1 (k=" << k1 << "): "; printArray(nums1, k1);
    cout << "-------------------\n";

    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "Original 2: "; printArray(nums2, nums2.size());
    int k2 = removeDuplicates(nums2);
    cout << "Unique 2 (k=" << k2 << "): "; printArray(nums2, k2);
    cout << "-------------------\n";

    vector<int> nums3 = {1, 1, 1};
    cout << "Original 3: "; printArray(nums3, nums3.size());
    int k3 = removeDuplicates(nums3);
    cout << "Unique 3 (k=" << k3 << "): "; printArray(nums3, k3);

    return 0;
}