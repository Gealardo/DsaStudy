#include<bits/stdc++.h>
using namespace std;

void printbinary(int x){
  for(int i=31;i>=0;i--){
    cout<<((x>>i)&1);
  }
  cout<<endl;
}

int main(){
  // 1. Basic NOT of a number
  printbinary(~1);
  
  // 2. Show ~n = -(n+1) 
 int x = 3;
 cout << "x = " << x << endl;
 cout << "~x = " << ~x << endl;       // Should print -4
 cout << "-(x+1) = " << -(x+1) << endl; // Should also print -4
 cout << "Are they equal? " << (~x == -(x+1)) << endl;
  
  // 3. Invert all bits
  int n=5;
  printbinary(n);
  printbinary(~n);
}