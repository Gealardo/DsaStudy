#include<bits/stdc++.h>
using namespace std;

void printbinary(int x){
  for(int i=31;i>=0;i--){
    cout<<((x>>i)&1);
  }
  cout<<endl;
}

int main(){
  // 1. Basic AND of two numbers
  cout<<"and :";
  int x=7,y=3;
  printbinary(x&y);
  
  // 2. Check even/odd using n & 1
  int n=22;
  if((n & 1)==1) cout<<n<<" is odd"<<endl;
  else cout<<n<<" is even"<<endl;
  
  // 3. Extract last 4 bits using mask

  int l=9;
  cout<<" last 4 digit of "<<l<<": ";
  printbinary(l&15);
  
}