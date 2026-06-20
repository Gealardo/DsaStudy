#include <bits/stdc++.h>
using namespace std;

// Version 1: Brute Force - O(N*K) using Set
vector<int> countDistinctBrute(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> ans;
    set<int>st;
    
    for(int i=0; i<n-k+1 ; i++){
          st.clear();//tells no. of distinct ele in a particular window
        for(int j=i; j<i+k;j++){
             st.insert(arr[j]);
        }
        ans.push_back(st.size());
    }
    set<int>().swap(st);
    
    return ans;
}

// Version 2: Hash Map Sliding Window - O(N)
// vector<int> countDistinctMap(const vector<int>& arr, int k) {
//     int n = arr.size();
//     vector<int> ans;
//     unordered_map<int, int> freq; // Stores element -> frequency
//     for(int i=0; i<k ;i++){
//          freq[arr[i]]++;
//     }
//     ans.push_back(freq.size());  
//     for(int j=k ; j<n ; j++){

//         int outel=arr[j-k];
//         freq[outel]--;

//         if(freq[outel]==0) freq.erase(outel);
//         int inel=arr[j];
//         freq[inel]++;

//         ans.push_back(freq.size());
//     }
    
//     return ans;
// }

vector<int> CDEIWs(vector<int>&arr,int k){
    int n=arr.size();
    unordered_map<int,int>map;
    int left=0,right=0;
    vector<int>answer;
    while(right<n){
        //count the frequency
        map[arr[right]]++;
        if(right-left+1 <k){
            right++;
        }
        else if(right-left+1 ==k){
            //update ans
            answer.push_back(map.size());
            //remove left
            map[arr[left]]--;
            if(map[arr[left]]==0) map.erase(arr[left]);
            left++;
            right++;
        }

    }
    return answer;
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

    vector<int> arr1 = {1, 2, 1, 3, 4, 2, 3};
    int k1 = 4;
    cout << "Array 1: "; printArray(arr1);
    cout << "K = " << k1 << "\n";
    cout << "Brute Force: "; printArray(countDistinctBrute(arr1, k1));
    cout << "Hash Map:    "; printArray(CDEIWs(arr1, k1));
    cout << "Expected: [3, 4, 4, 3]\n";
    cout << "-------------------\n";

    vector<int> arr2 = {4, 1, 1, 1, 1};
    int k2 = 3;
    cout << "Array 2: "; printArray(arr2);
    cout << "K = " << k2 << "\n";
    cout << "Brute Force: "; printArray(countDistinctBrute(arr2, k2));
    cout << "Hash Map:    "; printArray(CDEIWs(arr2, k2));
    cout << "Expected: [2, 1, 1]\n";
    cout << "-------------------\n";

    vector<int> arr3 = {1, 2, 3, 4, 5};
    int k3 = 2;
    cout << "Array 3: "; printArray(arr3);
    cout << "K = " << k3 << "\n";
    cout << "Brute Force: "; printArray(countDistinctBrute(arr3, k3));
    cout << "Hash Map:    "; printArray(CDEIWs(arr3, k3));
    cout << "Expected: [2, 2, 2, 2]\n";

    return 0;
}