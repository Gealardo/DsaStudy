#include<bits/stdc++.h>
using namespace std;
void printarr(vector<int>&arr,int n){
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertionSort(vector<int>&arr,int n){
    //  for(int i=1;i<n;i++){
    //     int key= arr[i];
    //    for(int j=i-1;j>=0;j--){
    //      if(arr[j]>=key) {
    //         swap(arr[j+1],arr[j]);
    //     }
    //      else break;
    //    }
    //  }   
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
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
    cout<<"Reversed : ";
    insertionSort(arr,s);
    printarr(arr,s);


}