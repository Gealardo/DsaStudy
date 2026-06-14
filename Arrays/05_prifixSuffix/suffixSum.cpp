#include<bits/stdc++.h>
using namespace std;
void printarr(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//------------O(n)-O(n)----------
void suffix(vector<int>arr,int n){
     vector<int>suffix(n);  //suffix arr making
     int sum=0;
     for(int i=n-1;i>=0;i--){
          sum+=arr[i];
          suffix[i]=sum;    //filling at each index
     }
     printarr(suffix,n);    // printing suffix arr
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
    cout<<"prefix : ";
    suffix(arr,s);
    


}