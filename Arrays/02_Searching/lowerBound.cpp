#include<bits/stdc++.h>
using namespace std;

int lb(vector<int>arr,int n,int tar){
    int low=0;
    int high=n-1;
    int lb=n;
    while(low<=high){
       int mid=low+(high-low)/2;
       if(arr[mid]>=tar){
          lb=min(lb,mid);
          high=mid-1;
       }
       else low=mid+1;
       
    }
    return lb;
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
    cout<<"enter the target ";
    cin>>tar;
   int lbx=lb(arr,s ,tar);
   cout<<"lower bound: "<<lbx<<endl;

}