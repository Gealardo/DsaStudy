#include<bits/stdc++.h>
using namespace std;

//  Aka Housh Robber | concept...


int sumAdj(int idx, vector<int>& arr) {
    
    if (idx < 0) return 0;

    if (idx == 0) return arr[idx];

    int pick = arr[idx] + sumAdj(idx - 2, arr);

    int notpick = 0 + sumAdj(idx - 1, arr);

    return max(pick, notpick);
}


int sumAdjmemo(int idx,vector<int>&arr,vector<int>&dp){
        
     if(idx<0) return 0;

     if(idx==0) return dp[idx]=arr[idx];

     if(dp[idx]!=-1) return dp[idx];

     int pick=arr[idx]+sumAdjmemo(idx-2,arr,dp);
     int notpick=0+sumAdjmemo(idx-1,arr,dp);

     return dp[idx]=max(pick,notpick);
    
}

int sumAdjTabu(int idx, const vector<int>& arr, vector<int>& dp2) {
    if (idx < 0) return 0;
    if (idx == 0) return arr[0]; //Handle single-element case safely

    dp2[0] = arr[0];
    dp2[1] = max(arr[0], arr[1]);

    for (int i = 2; i <= idx; i++) {
        dp2[i] = max(dp2[i-1], arr[i] + dp2[i-2]);
    }
    return dp2[idx];
}
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
    vector<int>arr={1,2,3,4,5};
    int index=4;
    int t1=sumAdj(index,arr);
    cout<<t1<<endl;
    
    vector<int>dp(index+1,-1);
    int t2= sumAdjmemo(index,arr,dp);
    cout<<t2<<endl;

    vector<int>dp2(index+1,-1);
    int t3=sumAdjTabu(index,arr,dp2);
    cout<<t3<<endl;

    int t4=sumAdjOptimal(index,arr);
    cout<<t4<<endl;

}