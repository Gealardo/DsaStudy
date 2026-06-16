#include <bits/stdc++.h>
using namespace std;

// Version 1: Brute Force - O(N*K)
int maxSumBruteForce(const vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return -1; //size shoulb be equal or larger that k
    int max_sum = INT_MIN; //store max sum of subarrays of size k
    for(int i=0;i<n-k+1;i++){
         int sum=0;
        for(int j=i;j<i+k;j++){
            sum+=arr[j];
        }
        max_sum=max(max_sum,sum);
    }
    return max_sum;
}

// Version 2: Sliding Window - O(N)
int maxSumSlidingWindow(const vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return -1; // subarray of size k;
    int max_sum = INT_MIN;
    int firstk=0;
    for(int i=0;i<k;i++){
       firstk+=arr[i];
    }
    max_sum=firstk;
    for(int i=k;i<n;i++){
        firstk=firstk+arr[i]-arr[i-k];
        max_sum=max(max_sum,firstk);
    }
    return max_sum;
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

    vector<int> arr1 = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k1 = 4;
    cout << "Array 1: "; printArray(arr1);
    cout << "K = " << k1 << "\n";
    cout << "Brute Force: " << maxSumBruteForce(arr1, k1) << " (Expected: 39)\n";
    cout << "Sliding Window: " << maxSumSlidingWindow(arr1, k1) << " (Expected: 39)\n";
    cout << "-------------------\n";

    vector<int> arr2 = {1, 1, 1, 1, 10, 10};
    int k2 = 2;
    cout << "Array 2: "; printArray(arr2);
    cout << "K = " << k2 << "\n";
    cout << "Brute Force: " << maxSumBruteForce(arr2, k2) << " (Expected: 20)\n";
    cout << "Sliding Window: " << maxSumSlidingWindow(arr2, k2) << " (Expected: 20)\n";
    cout << "-------------------\n";

    vector<int> arr3 = {5, 2, 9, 1, 7};
    int k3 = 1;
    cout << "Array 3: "; printArray(arr3);
    cout << "K = " << k3 << "\n";
    cout << "Brute Force: " << maxSumBruteForce(arr3, k3) << " (Expected: 9)\n";
    cout << "Sliding Window: " << maxSumSlidingWindow(arr3, k3) << " (Expected: 9)\n";
    cout << "-------------------\n";

    vector<int> arr4 = {1, 2, 3};
    int k4 = 5;
    cout << "Array 4: "; printArray(arr4);
    cout << "K = " << k4 << "\n";
    cout << "Brute Force: " << maxSumBruteForce(arr4, k4) << " (Expected: -1)\n";
    cout << "Sliding Window: " << maxSumSlidingWindow(arr4, k4) << " (Expected: -1)\n";

    return 0;
}