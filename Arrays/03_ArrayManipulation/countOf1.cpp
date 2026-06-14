#include<bits/stdc++.h>
using namespace std;

int countOf1(vector<int>arr){
   int  maxi=0;
    int i=0,j=0;
    int  count=0;
    // if(j==arr.size()) arr[j]=0;
    while(j<arr.size()){
        if(arr[j]==1){
            j++;
        }
        else{
            count=j-i;
            maxi=max(count,maxi);
            j++;
            i=j;
        }
    }
    count = j - i;
    maxi = max(count, maxi);
    
    return maxi;
}

int main(){
        int s;
    cout<<"enter size :";
    cin>>s;
    vector<int>arr(s);
    cout<<"enter the elements "<<endl;
    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    int x1=countOf1(arr);
    cout<<x1;
}
