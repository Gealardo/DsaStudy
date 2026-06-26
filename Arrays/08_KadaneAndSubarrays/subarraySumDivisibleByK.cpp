#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;
//brute force
void fun(vector<int>& arr, int k) {
    if (k == 0) return; 
    bool found=false;
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum = sum + arr[j];
            
            if (sum % k == 0) {
                found=true;
                cout<<"[ ";
                for (int x = i; x <= j; x++) {
                    cout << arr[x] << " ";
                }
                cout<<']';
                cout<<endl;
            }
        }
    }
    if(!found) cout<<"Not Found";
}
int fun1(vector<int>&arr,int k){
 int sum=0;
 int ans=0;
 int remender=0;
 unordered_map<int,int>up;
 up[remender]++;
 for(int i=0;i<arr.size();i++){
    sum=sum+arr[i];
    remender=sum%k;
    if(remender<0) remender=remender+k;
    ans=ans+up[remender];
    up[remender]++;

 }
 return ans;
}



int main(){
    int k=5;
    vector<int>arr={1,0,0,0,3};
     fun(arr,k);
     cout<<endl;
     int x=fun1(arr,k);
     cout<<x<<endl;
    
}