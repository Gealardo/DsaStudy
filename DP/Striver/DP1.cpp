#include<bits/stdc++.h>
using namespace std;

// 01 FEBBONACCI
// recursion 
int febb1(int n){
    if(n<2){
        return n;
    }
    return febb1(n-1)+febb1(n-2);
}

// recurtion + memoization

int febb2(int n,vector<int>&dparr){
    if(n<2){
        return n;
     }
    if(dparr[n]!=-1) return dparr[n];
    return dparr[n]=febb2(n-1,dparr)+febb2(n-2,dparr); 
}

// memo->tabulation
int febb3(int n, vector<int>& dparr2){
    if(n < 2)
        return n;

    dparr2[0] = 0;
    dparr2[1] = 1;

    for(int i = 2; i <= n; i++){
        dparr2[i] = dparr2[i-1] + dparr2[i-2];
    }

    return dparr2[n];
}

// more space optimization
int febb4(int n){
  int prev2=0;
  int prev=1;
  if(n<2){
    return n;
  }
  for(int i=2;i<=n;i++){
      int curr=prev+prev2;
      prev2=prev;
      prev=curr;
  }
  return prev;
}

int main(){

    //approch 1
    int t1=febb1(8);
    cout<<t1<<endl;
     
    //approch 2
    int n=1;
    vector<int>dparr(n+1,-1);
    int t2=febb2(n,dparr);
    cout<<t2<<endl;
     
    //approch 3
    vector<int>dparr2(n+1,-1);
    int t3=febb3(n,dparr2);
    cout<<t3<<endl;  
    
    //approch 4  optimal O(n),O(1);
    int t4=febb4(n);
    cout<<t4<<endl;

}