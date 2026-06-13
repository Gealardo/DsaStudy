#include<bits/stdc++.h>
using namespace std;

vector<int> insertAtBegin(vector<int>&arr,int val,int n){
     for(int i=n-1;i>=0;i--){
        arr[i+1]=arr[i];
     }
     arr[0]=val;
     return arr;
}
vector<int> insertAtKth(vector<int>&arr,int val,int n,int k){
    //last position  
    if(k==n){
        arr[n]=val;
        return arr;
      }
    if(k < 0 || k > n){
    cout<<"Invalid Index"<<endl;

    return arr;

}
    for(int i=n-1;i>=k;i--){
        arr[i+1]=arr[i];
    }  
    arr[k]=val;
    return arr;
}

int main(){

     int s;
    cout<<"enter size of arr : ";
    cin>>s;
    vector<int>arr(10);
    cout<<endl;
    cout<<"enter elements of array in sorted order"<<endl;

    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    int insert_val;
    cout<<"insert value : ";
    cin>>insert_val;
    int  atIndex;
    cout<<"insert index : ";
    cin>>atIndex;
    vector<int> modiArr=insertAtKth(arr,insert_val,s,atIndex);
    for(int i=0;i<=s;i++){
        cout<<modiArr[i]<<" ";
    }
    cout<<endl;


}