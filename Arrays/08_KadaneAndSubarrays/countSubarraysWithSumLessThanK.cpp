#include<bits/stdc++.h>
using namespace std;

int countSubarraySumisK(vector<int>&arr,int k){
    int count=0;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
              sum+=arr[j];
              if(sum<k) count++;
        }
    }
    return count;
}



int main(){
    vector<int>arr= {5, 3, 1};
    int k=4;
    int c=countSubarraySumisK(arr,k);
    cout<<c<<endl;
    
}