#include <bits/stdc++.h>
using namespace std;

// 🛑 VERSION 1: Check if pair exists (Return true/false)
bool pairSumExists(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while(left<right){
         if((arr[left]+arr[right])==target) return true;
         else if((arr[left]+arr[right])>target) right--;
         else left++;
    }
    
    return false;
}

// 🛑 VERSION 2: Return the actual pair indices
vector<int> pairSumIndices(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
     while(left<right){
         if((arr[left]+arr[right])==target) return {left,right};
         else if((arr[left]+arr[right])>target) right--;
         else left++;
    }
    
    
    return {-1, -1};
}

// 🛑 VERSION 3: Return all unique pairs 
vector<pair<int, int>> pairSumAll(vector<int>& arr, int target) {
    vector<pair<int, int>> result;
    int left = 0;
    int right = arr.size() - 1;
     while(left<right){
         if((arr[left]+arr[right])==target){
            result.push_back({arr[left],arr[right]}); 
            while(left<right && arr[left]==arr[left+1]) left++;
            while(left<right && arr[right]==arr[right-1]) right--;            
            left++;right--;
         }
         else if((arr[left]+arr[right])>target) right--;
         else left++;
    }
    
    
    return result;
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

    // Test Case 1: Pair exists
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    int target1 = 8;
    cout << "Array 1: "; printArray(arr1);
    cout << "Target: " << target1 << endl;
    cout << "Pair exists: " << (pairSumExists(arr1, target1) ? "YES" : "NO") << endl;
    vector<int> indices1 = pairSumIndices(arr1, target1);
    if (indices1[0] != -1) {
        cout << "Indices: [" << indices1[0] << ", " << indices1[1] << "]" << endl;
        cout << "Values: [" << arr1[indices1[0]] << ", " << arr1[indices1[1]] << "]" << endl;
    }
    cout << "-------------------\n";

    // Test Case 2: No pair exists
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int target2 = 10;
    cout << "Array 2: "; printArray(arr2);
    cout << "Target: " << target2 << endl;
    cout << "Pair exists: " << (pairSumExists(arr2, target2) ? "YES" : "NO") << endl;
    cout << "-------------------\n";

    // Test Case 3: Multiple pairs (test Version 3)
    vector<int> arr3 ={2, 2, 2, 8, 8};
    int target3 = 10;
    cout << "Array 3: "; printArray(arr3);
    cout << "Target: " << target3 << endl;
    vector<pair<int, int>> allPairs = pairSumAll(arr3, target3);
    cout << "All pairs: ";
    for (auto& p : allPairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    cout << "-------------------\n";

    // Test Case 4: Edge case - empty array
    vector<int> arr4 = {};
    int target4 = 5;
    cout << "Array 4: "; printArray(arr4);
    cout << "Target: " << target4 << endl;
    cout << "Pair exists: " << (pairSumExists(arr4, target4) ? "YES" : "NO") << endl;
    cout << "-------------------\n";

    // Test Case 5: Edge case - single element
    vector<int> arr5 = {5};
    int target5 = 10;
    cout << "Array 5: "; printArray(arr5);
    cout << "Target: " << target5 << endl;
    cout << "Pair exists: " << (pairSumExists(arr5, target5) ? "YES" : "NO") << endl;

    return 0;
}