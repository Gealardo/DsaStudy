#include<bits/stdc++.h>
using namespace std;

//binary search
int targetAt(vector<int>arr,int n,int k){
    if(n==0) return -1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k) return mid;
        else if(arr[mid]>k) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main(){
    int s;
    cout<<"enter size of arr : ";
    cin>>s;
    vector<int>arr(s);
    cout<<endl;
    cout<<"enter elements of array in sorted order"<<endl;

    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    int tar;
    cout<<"enter target element: ";
    cin>>tar;
    cout<<endl;
    int index=targetAt(arr,s,tar);
    cout<<"target at index at: "<<index<<endl;
}