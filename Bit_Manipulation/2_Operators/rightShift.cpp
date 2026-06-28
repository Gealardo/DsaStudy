#include<bits/stdc++.h>
using namespace std;

void printbinary(int x){
  for(int i=31;i>=0;i--){
    cout<<((x>>i)&1);
  }
  cout<<endl;
}

int main(){
  // 1. Basic right shift
  int x=25;
  printbinary(x>>1);
  
  // 2. Divide by 2, 4, 8 using >>
   cout<<(x>>1)<<endl;
   cout<<(x>>2)<<endl;
   cout<<(x>>3)<<endl;
  
  // 3. Signed vs unsigned behavior----------(NEED WORK);
  
  //even /odd;
  int y=2;
  if((y>>31)&1) cout<<y<<" is negative no"<<endl;
  else cout<<y<<" is a pos no "<<endl;
}