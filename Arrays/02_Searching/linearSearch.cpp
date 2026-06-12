#include<bits/stdc++.h>
using namespace std;
int found(int arr[],int tar,int s){
    for(int i=0;i<s;i++){
        if(arr[i]==tar) return i;
    }
   return -1;
}

int main(){
    int target;
    cout<<"enter target"<<endl;
    cin>>target;
   int arr[5]={1,4,5,6,7};
   int targetat=found(arr,target,5);
   cout<<"index : "<<targetat<<endl;

}