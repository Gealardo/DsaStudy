#include<bits/stdc++.h>
using namespace std;
long long inBinary(int n){
    long long ans=0;
    long long place=1;
    while(n>0){
        ans=ans+ (n%2)*place;
        n=n/2;
        place=place*10;

    }
    return ans;
}

int inDecimal(int x){
    int place =1;
    int ans=0;
    while(x>0){
        ans=ans+(x%10)*place;
        place=place*2;
        x=x/10;
    }
    return ans;
}
// cpp code for decimal to binary

  


int main(){
    int n;
    cout <<"Enter a number:  ";
    cin>>n;
    cout<<endl;
    cout<<"In binary "<<inBinary(n)<<endl;

    cout<<"Binary to decimal: "<<inDecimal(1010000001)<<endl;
    return 0;
}