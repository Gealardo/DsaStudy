#include <bits/stdc++.h>
using namespace std;


int partition(vector<int>& arr, int low, int high) {
     int pivot=high;
     int i=low-1,j=low;
     while(j!=pivot){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
     }
        i++;
        swap(arr[i],arr[pivot]);
        return i;
     



}


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 1. Get the pivot index
        int pi = partition(arr, low, high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
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
    vector<int> arr1 = {10, 7, 8, 9, 1, 5};
    cout << "Original 1: "; printArray(arr1);
    quickSort(arr1, 0, arr1.size() - 1);
    cout << "Sorted 1:   "; printArray(arr1);
    cout << "-------------------\n";

    // Test Case 2: Array with duplicates
    vector<int> arr2 = {5, 2, 5, 8, 1, 5, 3};
    cout << "Original 2: "; printArray(arr2);
    quickSort(arr2, 0, arr2.size() - 1);
    cout << "Sorted 2:   "; printArray(arr2);
    cout << "-------------------\n";

    // Test Case 3: Already sorted array
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Original 3: "; printArray(arr3);
    quickSort(arr3, 0, arr3.size() - 1);
    cout << "Sorted 3:   "; printArray(arr3);

    return 0;
}