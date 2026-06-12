#include<bits/stdc++.h>
using namespace std;

int secondl(int arr[],int s){
    int l=arr[0];
    int sl=INT_MIN;
    if(s==1 || s==0) return -1;
    for(int i=0;i<s;i++){
        //el>l;
        if(arr[i]>l){
            sl=l;
            l=arr[i];
        }
        //el<lar but el>sl
        if(arr[i]<l && arr[i]>sl){
            sl=arr[i];
        }
    }
    return sl;
}

int main(){
    int arr[5]={23,5};
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    int sl=secondl(arr,2);
    cout<<sl;

}