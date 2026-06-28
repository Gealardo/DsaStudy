#include<bits/stdc++.h>
using namespace std;

void printbinary(int x){
  for(int i=31;i>=0;i--){
    cout<<((x>>i)&1);
  }
  cout<<endl;
}

int main(){
  // 1. Basic XOR of two numbers
  printbinary(3^1);
  
  // 2. Toggle a specific bit
  int n = 5;  // 00000101
// Toggle bit 2 (the middle 1)
printbinary(n ^ (1 << 2));  // 00000001 (bit flipped!)

// Toggle bit 0 (the rightmost 1)
printbinary(n ^ (1 << 0));  // 00000100 (bit flipped!)

  
  // 3. Swap two numbers without temp
  int y=15;
  int z=21;
  cout<<"Before : y,z "<<y<<" "<<z<<endl;
  y=y^z;

  z=z^y;
  y=y^z;
   cout<<"After : y,z "<<y<<" "<<z<<endl;

}