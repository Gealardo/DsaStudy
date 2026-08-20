#include<bits/stdc++.h>
using namespace std;

void print(string s, int n){ 
  if(n==0) return;
  cout<<s<<endl;
  print(s,n-1);
}

void number(int n){
  if(n==0) return;
  cout<<n<<" ";
  number(n-1);
}

void number(int x,int n){
  if(n<x) return;
  cout<<x<<" ";
  number(x+1,n);
}

int fact(int n){
  if(n==0) return 1;
  return n*fact(n-1);
}

int fibbo(int n){
  if(n==0||n==1) return n;
  return fibbo(n-1)+fibbo(n-2);
}

int sumrec(int n){
  if(n==0) return 0;
   return n+sumrec(n-1);
}

int sumrec2(int n,int sum,int x){
  if(x==n) return n;
  return sum+=x+sumrec2(n,sum,x+1);
}

void reverse(vector<int> &arr,int i,int j){
  if(i>=j) return;
  swap(arr[i],arr[j]);
  reverse(arr,i+1,j-1);
}

int main(){

 cout<<"Name 5 times: "<<endl;
 print("Ayun",5);

 cout<<"\nN to 1: "<<endl;
 number(5);

 cout<<"\n\n1 to N: "<<endl;
 number(1,5);

 int x=5;
 cout<<"\n\nFactoria of "<<x<<" : "<<endl;
 cout<<fact(x)<<endl;

 int y=4;
 cout<<"\n\nFibbo "<<y<<"th : "<<endl;
 cout<<fibbo(y)<<endl;

 
 int z=98;
 cout<<"\n\nSum of 1 to "<<z<<" : "<<endl;
 cout<<sumrec(z);

 int k=98;
 cout<<"\n\nSum of 1 to "<<k<<" : "<<endl;
 cout<<sumrec2(k,0,1);

 cout<<"\nRev Array: "<<endl;
 vector<int>arr={1,2,5,8};
 reverse(arr,0,arr.size()-1);
 for(const auto x:arr) cout<<x<<" ";
}
