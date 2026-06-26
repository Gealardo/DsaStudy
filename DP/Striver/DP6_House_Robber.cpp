

#include<bits/stdc++.h>
using namespace std;

// circular concept ->imposible two have both aar[0],arr[n-1] in answer..

// house robber ||.

int sumAdjOptimal(int idx, const vector<int>& arr) {
    if (idx < 0) return 0;
    if (idx == 0) return arr[0]; //Handle single-element case safely

    int prev2= arr[0];
    int prev = max(arr[0], arr[1]);

    for (int i = 2; i <= idx; i++) {
        int curr = max(prev, arr[i] + prev2);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int main(){
   
    vector<int>arr={1,6,3,7,8};
    vector<int>temp1,temp2;
    for(int i=0;i<arr.size();i++){
        if(i!=0) temp1.push_back(arr[i]);
        if(i!=arr.size()-1) temp2.push_back(arr[i]);
    }
    if(arr.size()==1){
        cout<<arr[0]<<endl;
        return 0;
    }
    int t1=sumAdjOptimal(temp1.size()-1,temp1);
    int t2=sumAdjOptimal(temp2.size()-1,temp2);
   
    int ans=max(t1,t2);
    cout<<ans<<endl;

    return 0;
}