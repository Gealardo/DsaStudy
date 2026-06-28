#include<bits/stdc++.h>
using namespace std;

void printbinary(int x){
  for(int i=31;i>=0;i--){
    cout<<((x>>i)&1);
  }
  cout<<endl;
}

int main(){
  // 1. Basic left shift
  printbinary(5 << 1); // 5 * 2 = 10
  
  // 2. Multiply by 2, 4, 8 using <<
  printbinary(5 << 2); // 5 * 4 = 20
  printbinary(5 << 3); // 5 * 8 = 40
  
  // 3. Show overflow behavior
  int x = INT_MAX;
  cout << "Before left shift: " << x << endl;
  printbinary(x);
  x = x << 1; // This will cause overflow
  cout << "After left shift: " << x << endl;
  printbinary(x);

}