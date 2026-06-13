#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr) {
    int low=0;
    int high=arr.size()-1;
    while(low<high){
        swap(arr[low],arr[high]);
        low++; high--;
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

    vector<int> arr1 = {1, 2, 3, 4, 5}; // Odd length
    vector<int> arr2 = {1, 2, 3, 4};    // Even length
    vector<int> arr3 = {9};             // Single element
    vector<int> arr4 = {};              // Empty array

    cout << "Original 1: "; printArray(arr1);
    reverseArray(arr1);
    cout << "Reversed 1: "; printArray(arr1);
    cout << "-------------------\n";

    cout << "Original 2: "; printArray(arr2);
    reverseArray(arr2);
    cout << "Reversed 2: "; printArray(arr2);
    cout << "-------------------\n";

    cout << "Original 3: "; printArray(arr3);
    reverseArray(arr3);
    cout << "Reversed 3: "; printArray(arr3);

    return 0;
}