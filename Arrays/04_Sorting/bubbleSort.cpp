#include<bits/stdc++.h>
using namespace std;
void printarr(vector<int>&arr,int n){
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubbleSort(vector<int>&arr,int n){
     
     for(int i=0;i<n-1;i++){
        bool isSwap=false;//traking that is swap occure even once
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap) break;//if no swap in firt time then array is alredy sorted 
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
    bubbleSort(arr,s);
    printarr(arr,s);


}