#include<bits/stdc++.h>
using namespace std;

// find a specific bit;


int getbit(int n,int pos){
  //make mask
  int m=1<<pos;
  if((n&m)==0){
    return 0;
  }
  else return 1;
}

int main(){
//------example----------------------------
   int x=10;
   //find its 1 position bit
   //make a mask 0000...0010;
   // do and if result 0 then it was 0 else 1;
   if((10&2)==0) {
    cout<<0<<endl;
   }
   else cout<<1<<endl;
//------------------------------------------
   int n;
   cout<<"enter a no: ";
   cin>>n;
   cout<<endl;
   int pos;
   cout<<"bit pos : ";
   cin>>pos;

   cout<<getbit(n,pos);


 return 0;
}




