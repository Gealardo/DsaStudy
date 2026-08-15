// Given an array arr[], where each element is at most k positions away from its correct position in the sorted order.
// Your task is to restore the sorted order of arr[] by rearranging the elements in place.

// Note: Don't use any sort() method.

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int l=0;
        int r=0;
        while(r<n){
            pq.push(arr[r]);
            
            if(pq.size()==k+1){
                arr[l]=pq.top();
                pq.pop();
                l++;
            }
            r++;
        }
        //min heap still left with the k element;
        while(!pq.empty()){
            arr[l]=pq.top();
            pq.pop();
            l++;
        }
        
    }
};




int main() {
    Solution solver;
    
    // Sample Input: A k-sorted array where k = 2
    // Each element is at most 2 positions away from its sorted target index.
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 2;

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Call the function
    solver.nearlySorted(arr, k);
      cout << "Sorted Array:   ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}