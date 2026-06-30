//has only one setbit

#include<bits/stdc++.h>
using namespace std;
bool isPowerOf2(int n){
    if(n<2) return false;
    //has only one setbit->so clear lowest set bit n become zero
    int mask=(n-1);
    if((n&mask)==0) return true;
    
    return false;

}

int main(){
  int n;
  cout<<"enter a no :";
  cin>>n;


  bool IsPow2=isPowerOf2(n);
  cout<<IsPow2<<endl;
}