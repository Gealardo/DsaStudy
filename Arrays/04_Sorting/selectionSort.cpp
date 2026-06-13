#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
   
   for(int i=0;i<n-1;i++){
    int min=i;
      for(int j=i+1;j<n;j++){
         if(arr[j]<arr[min]){
            min=j;
         }
      }

     if(min!=i) swap(arr[min],arr[i]);
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

    // Test Case 1: Standard unsorted array
    vector<int> arr1 = {64, 25, 12, 22, 11};
    cout << "Original 1: "; printArray(arr1);
    selectionSort(arr1, arr1.size());
    cout << "Sorted 1:   "; printArray(arr1);
    cout << "-------------------\n";

    // Test Case 2: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Original 2: "; printArray(arr2);
    selectionSort(arr2, arr2.size());
    cout << "Sorted 2:   "; printArray(arr2);
    cout << "-------------------\n";

    // Test Case 3: Single element
    vector<int> arr3 = {42};
    cout << "Original 3: "; printArray(arr3);
    selectionSort(arr3, arr3.size());
    cout << "Sorted 3:   "; printArray(arr3);

    return 0;
}