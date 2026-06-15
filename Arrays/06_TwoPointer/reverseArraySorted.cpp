#include<bits/stdc++.h>
using namespace std;

// ---------- BRUTE ----------
void reverseBrute(vector<int>& arr){
    int n = arr.size();
    
    if(n==0) return;

    vector < int > rev;
    for(int i=n-1 ; i>=0; i--){
       rev.push_back(arr[i]);
    }
    for(int i=0; i<n ;i++){
       arr[i]=rev[i];
    }
}

// ---------- OPTIMAL ----------
void reverseOptimal(vector<int>& arr){
     int n = arr.size();
     if(n==0) return;
     int l=0 , r=n-1;
     while(l<r){
        swap(arr[l],arr[r]);
        l++; r--;
     } 
}

void print(vector<int>& arr){
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;
}

int main(){

    vector<int> arr1 = {1,2,3,4,5};

    cout << "Original: ";
    print(arr1);

    reverseBrute(arr1);

    cout << "Reversed: ";
    print(arr1);
    vector<int> arr2 = {21, 43 ,56 ,78 ,90};
     cout << "Original: ";
    print(arr2);
    reverseOptimal(arr2);

    cout << "Reversed: ";
    print(arr2);

    return 0;
}