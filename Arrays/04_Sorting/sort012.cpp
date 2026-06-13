#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int>& arr) {
    int low=0,mid=0;
    int high=arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
           swap(arr[mid],arr[low]);
           low++; mid++;
        }
        else if(arr[mid]==1){
                mid++;
        }
        else{
          swap(arr[mid],arr[high]);
          high--;
        }
        
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
    

    vector<int> arr1 = {0, 1, 2, 0, 1, 2};
    cout << "Original 1: "; printArray(arr1);
    sort012(arr1);
    cout << "Sorted 1:   "; printArray(arr1);
    cout << "-------------------\n";

    vector<int> arr2 = {2, 2, 2, 1, 1, 0, 0};
    cout << "Original 2: "; printArray(arr2);
    sort012(arr2);
    cout << "Sorted 2:   "; printArray(arr2);

    return 0;
}