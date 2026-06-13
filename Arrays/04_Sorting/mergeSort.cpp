#include<bits/stdc++.h>
using namespace std;

void printarr(vector<int>&arr,int n){
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//--------------merge---------
void merge(vector<int>&arr,int low,int mid,int high){
    int n=high-low+1;
    vector<int>ans(n);
    int i=low;
    int j=mid+1;
    int k=0;
   while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            ans[k++] = arr[i++];
        } else {
            ans[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        ans[k++] = arr[i++];
    }
   while (j <= high) {
        ans[k++] = arr[j++];
    }
    for(int i=0;i<n;i++){
        arr[i+low]=ans[i];
    }
    
    
}

//--------divide-----------
void divide(vector<int>&arr,int low,int high){
    if(low>=high) return;
    int mid=low+(high-low)/2;
    divide(arr,low,mid);
    divide(arr,mid+1,high);
    merge(arr,low,mid,high);
}





int main(){
    int s;
    cout<<"enter size :";
    cin>>s;
    vector<int>arr(s);
    cout<<"enter the elements "<<endl;
    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    cout<<"Original : ";
    printarr(arr,s);
    divide(arr,0,s-1);
     printarr(arr,s);

}