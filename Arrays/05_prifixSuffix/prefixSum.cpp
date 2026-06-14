#include<bits/stdc++.h>
using namespace std;
void printarr(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//------------O(n)-O(n)----------
void prefix(vector<int>&arr,int n){
     vector<int>prefix(n); //prefix arr making
     if(n==0) return;
     prefix[0]=arr[0];
     for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];    //filling at each index
     }
     printarr(prefix,n);    // printing prefix arr
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
    prefix(arr,s);
    


}