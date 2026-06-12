#include<bits/stdc++.h>
using namespace std;
//upper->last occur
int lb(vector<int>arr,int n,int tar){
    int low=0;
    int high=n-1;
    int lb=n;
    while(low<=high){
       int mid=low+(high-low)/2;
       if(arr[mid]>tar){
          lb=min(lb,mid);
          high=mid-1;
       }
       else low=mid+1;
       
    }
    return lb;
}
//------------last occurenc------------------
int firtocc(vector<int>arr,int n,int k){
     int low=0;
    int high=n-1;
    int occ=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            occ=min(n,mid);
             low=mid+1;
        }
        else if(arr[mid]<k) low=mid+1;
        else high=mid-1;
     }
     return occ;
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
   if(lbx<s && arr[lbx-1]==tar) cout<<"first occurrence at : "<<lbx-1<<endl;
   else cout<<"element not found"<<endl;

   //------------------
   int x=firtocc(arr,s,tar);
   cout<<"last occ at : "<<x<<endl;

}