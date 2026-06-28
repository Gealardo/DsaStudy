#include<bits/stdc++.h>
using namespace std;
// finding the 2's complement of a number



// decimal to binary
void printbinary(int x){
  for(int i=31;i>=0;i--){
    cout<<((x>>i)&1);
  }
  cout<<endl;
}

int main(){

  int x=5;

  // oringinal in binary
  cout<<"binary representation : "<<endl;
  printbinary(x);
  
  //1's comp
  int y=~x ;
  cout<<"1's : ";
  printbinary(y);
  // now twos complement is 1's comp + 1
  int z=y+1;
  cout<<"2's : ";
  printbinary(z);

}