#include<bits/stdc++.h>
using namespace std;
void printarr(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//-------------------------------------
    /*Difference array method-> solve the range updates in array fastly
     its intiution-> start from exact pont but do not stop of updating..
     logic for querie(l,r,x)-> add x at l, and add -x at r+1 if(r+1<n)
     finally answer array after arr quaries will be prefix summ of arr..
     */
 void  quarie(vector<int>&arr,int l,int r,int x){
          if(l<0 || l>=arr.size()) return;
          arr[l]+=x;
          if((r+1)<arr.size()) arr[r+1]-=x;   
 }


//=======================================


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
    vector<int>arr(s,0);
   
    cout<<"Original : ";
    printarr(arr,s);
    quarie(arr,2,4,2);
    quarie(arr,-1,4,2);
    quarie(arr,2,9,-2);
    quarie(arr,2,4,2);
    cout<<"updated array : ";
    prefix(arr,s);
    


}