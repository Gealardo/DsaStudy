#include<bits/stdc++.h>
using namespace std;


void tooglebit(int n,int pos){
  //make mask
  int m=1<<pos;
   int l=n^m;
   cout<<((l>>pos)&1 )<<endl;
 }

int main(){

   int n;
   cout<<"enter a no: ";
   cin>>n;
   cout<<endl;
   int pos;
   cout<<"bit pos : ";
   cin>>pos;

   tooglebit(n,pos);


 return 0;
}





