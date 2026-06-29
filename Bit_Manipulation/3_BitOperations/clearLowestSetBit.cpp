#include<bits/stdc++.h>
using namespace std;



void printbinary(int k){
   for(int i=31;i>=0;i--){
    cout<<((k>>i)&1);
   }
   cout<<endl;
}

int main(){
  int n;
  cout<<"enter a no. : ";
  cin>>n;

  printbinary(n);
  printbinary(n&(n-1));

}