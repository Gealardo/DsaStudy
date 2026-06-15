#include <bits/stdc++.h>
using namespace std;

// 🛑 VERSION 1: Merge into a new array (O(n+m) space)
vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int n1=arr1.size(),n2=arr2.size();
    vector<int> result;
    int i = 0, j = 0;
    while(i<n1 && j<n2){
        if(arr1[i]>arr2[j]){
            result.push_back(arr2[j]);
            j++;
        }
        else{
            result.push_back(arr1[i]);
            i++;
        }
    }
    while(i<n1){
        result.push_back(arr1[i]);
        i++;
    }
     while(j<n2){
        result.push_back(arr2[j]);
        j++;
    }
    
    
    return result;
}

// arr1 has size m+n, with first m elements valid and last n elements as 0
void mergeInPlace(vector<int>& arr1, int m, const vector<int>& arr2, int n) {
   int i=m-1 , j=n-1 , k=m+n-1;
   while(j>=0 && i>=0){
     if(arr1[i]<arr2[j]) {
        arr1[k]=arr2[j];
        k--; j--;
     }
     else{
        arr1[k]=arr1[i];
        k--; i--;
     }
   }

   while(j>=0){
     arr1[k]=arr2[j];
     j--; k--;
   }

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

    // Test Case 1: Standard merge
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    cout << "Array 1: "; printArray(arr1);
    cout << "Array 2: "; printArray(arr2);
    vector<int> merged = mergeSortedArrays(arr1, arr2);
    cout << "Merged:  "; printArray(merged);
    cout << "-------------------\n";

    // Test Case 2: Different sizes
    vector<int> arr3 = {1, 2, 3};
    vector<int> arr4 = {4, 5, 6, 7, 8};
    cout << "Array 3: "; printArray(arr3);
    cout << "Array 4: "; printArray(arr4);
    vector<int> merged2 = mergeSortedArrays(arr3, arr4);
    cout << "Merged:  "; printArray(merged2);
    cout << "-------------------\n";

    // Test Case 3: One empty array
    vector<int> arr5 = {1, 2, 3};
    vector<int> arr6 = {};
    cout << "Array 5: "; printArray(arr5);
    cout << "Array 6: "; printArray(arr6);
    vector<int> merged3 = mergeSortedArrays(arr5, arr6);
    cout << "Merged:  "; printArray(merged3);
    cout << "-------------------\n";

    // Test Case 4: In-place merge (LeetCode 88 style)
    vector<int> arr7 = {1, 2, 3, 0, 0, 0}; // m=3, n=3
    vector<int> arr8 = {2, 5, 6};
    cout << "Array 7 (before): "; printArray(arr7);
    cout << "Array 8: "; printArray(arr8);
    mergeInPlace(arr7, 3, arr8, 3);
    cout << "Array 7 (after):  "; printArray(arr7);
    cout << "Expected: [1, 2, 2, 3, 5, 6]\n";
    cout << "-------------------\n";

    // Test Case 5: Duplicates
    vector<int> arr9 = {1, 2, 2, 3};
    vector<int> arr10 = {2, 2, 4};
    cout << "Array 9: "; printArray(arr9);
    cout << "Array 10: "; printArray(arr10);
    vector<int> merged4 = mergeSortedArrays(arr9, arr10);
    cout << "Merged:  "; printArray(merged4);

    return 0;
}