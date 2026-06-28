#include<bits/stdc++.h>
using namespace std;

void printbinary(int x){
  for(int i=31;i>=0;i--){
    cout<<((x>>i)&1);
  }
  cout<<endl;
}

int main(){
  // 1. Basic OR of two numbers
  int n=(2|4);
  printbinary(n);
  
  // 2. Set a specific bit to 1
  int x=5 ;// 101
  printbinary(x|2); // middle bit will become 1;
  
  // 3. Combine two flags
  int z=0;
  int y=1;
  printbinary(z|y); // 0|1=1;
}