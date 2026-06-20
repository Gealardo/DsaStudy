#include<bits/stdc++.h>
using namespace std;


vector<int> maxel(vector<int>arr,int k){
    int n=arr.size();
    int left=0,right=0;
    deque<int>dq;
    vector<int>ans;
    while(right<n){
        while(!dq.empty() && arr[right]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(right);
        if(right-left+1 <k){
            right++;
        }
        else if(right-left +1 ==k){
             ans.push_back(arr[dq.front()]);
             if(dq.front()==left){
                dq.pop_front();
             }
             left++;
             right++;
        }
    }
    return ans;
}

int main(){
    int k=3;
    vector<int>arr={1,3,-4,-5,8,9};
    vector<int>ans=maxel(arr,k);
    for(const auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}