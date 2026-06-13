#include<bits/stdc++.h>
using namespace std;

void deleteFromPosition(vector<int>& arr, int& n, int pos){
     if(pos<1 || pos>n) return;
     if(pos==n) {
        n--;
        return;
     } // last del case
     //first and middle case
     for(int i=pos-1;i<n-1;i++){
          arr[i]=arr[i+1];
     }
     n--;
     return;
}

int main(){

    vector<int> arr = {10,20,30,40,50};

    int n = arr.size();

    int pos = 5;

    deleteFromPosition(arr,n,pos);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}