#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&nums,int n){
     cout<<"elements are "<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
//-----brute force o(n^2)---------
void productExeptSelf(vector<int>&nums,int n){
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int mul=1;
        for(int j=0;j<n;j++){
           if(j!=i) mul=mul*nums[j];
        }
        ans[i]=mul;
  }
  print(ans,n);
}
//-----------divide method---O(n)-----
void productByDivide(vector<int>&nums,int n){
 int mul=1;
 int mul_without_zero=1;
 int count_zero=0;
 for(int i=0;i<n;i++){
    mul=mul*nums[i];
    if(nums[i]==0){
        count_zero++;
    }
    else mul_without_zero=mul_without_zero*nums[i];
 }
 vector<int>ans(n);
   if(count_zero>=2){
    print(ans,n);
    return;
   }
   for(int j=0;j<n;j++){
      if(count_zero==0){
        ans[j]=mul/nums[j];
      }
      if(count_zero==1) {
        if(nums[j]==0) ans[j]=mul_without_zero;
        else ans[j]=mul/nums[j];
      }
   }

   print(ans,n);
   return;

}
//-------------optimal---without div----O(n)O(n)----
void optimalProduct(vector<int>&nums,int n){
    vector<int>left(n);
    left[0]=1;
    for(int i=1;i<n;i++){
        left[i]=left[i-1]*nums[i-1];
    }
    vector<int>right(n);
    right[n-1]=1;
    for(int i=n-2;i>=0;i--){
        right[i]=right[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++){
        nums[i]=left[i]*right[i];
    }
    return;

}
//-------------optimal---without div----O(n)O(1)----
void optimalProduct2(vector<int>&nums,int n){
    vector<int>left(n);
    left[0]=1;
    for(int i=1;i<n;i++){
        left[i]=left[i-1]*nums[i-1];
    }
    vector<int>ans=left;
    int right=1;
    for(int r=n-1;r>=0;r--){
        ans[r]*=right;
        right*=nums[r];
    }
    print(ans,n);
    return;

}

int main(){
    int s;
    cout<<"enter the size: ";
    cin>>s;
    vector<int>nums(s);
    cout<<"enter the elements "<<endl;
    for(int i=0;i<s;i++){
        cin>>nums[i];
    }
    print(nums,s);
    cout<<"products ";
    productExeptSelf(nums,s);
    cout<<"products by div ";
    productByDivide(nums,s);    
    cout<<"--optimal---"<<endl;
    optimalProduct(nums,s);
    print(nums,s);
    optimalProduct2(nums,s);
}