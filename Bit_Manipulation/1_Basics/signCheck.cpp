#include<bits/stdc++.h>
using namespace std;



void checkSign(int n){
    // n>>x  -> rightmost fallen off by leftmost bit copying
    // now after removing 31 bits, the leftmost bit will be at the rightmost position.
    // and now we do & with one so that we can remove other bits left to the signbit and we can check if the sign bit is 1 or 0.
    if(n>>31 & 1==1) cout<<"Negative number"<<endl;
    else cout<<"Positive number"<<endl;

}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    checkSign(n);
    return 0;
}
      

 
  