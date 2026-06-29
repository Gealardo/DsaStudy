#include<bits/stdc++.h>
using namespace std;

// find a specific bit;


void setbit(int n,int pos){
  //make mask
  int m=1<<pos;
   int l=n|m;
   cout<<((l>>pos)&1 )<<endl;
 }

int main(){
//------example----------------------------
   int x=10;
   //make  its 1 position bit 1
   //make a mask 0000...0010;
   // do OR then at that pos there will be 1;
    int y=10|2;
     cout<<((x>>1)&1)<<endl;
   
//------------------------------------------
   int n;
   cout<<"enter a no: ";
   cin>>n;
   cout<<endl;
   int pos;
   cout<<"bit pos : ";
   cin>>pos;

   setbit(n,pos);


 return 0;
}





