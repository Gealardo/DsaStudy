#include<bits/stdc++.h>
using namespace std;

//        BRUTE FORCE METHOD
vector<int> firstNegative(const vector<int>&arr, int k){
    int n = arr.size();
    vector<int>ans(n-k+1);
    for(int i=0 ; i<n-k+1;i++){
        ans[i]=0;
          for(int j=i ; j<i+k;j++){
            if(arr[j]<0) {
                ans[i]=arr[j];
                break;
            }
          }
    }
    return ans;
}

// OPTIMAL SLIDING WINDOW
// vector<int> firstNegativeOP(const vector<int>&arr, int k){
//     int n = arr.size();
//     vector<int>ans;
//     queue<int>q;
//     int i=0,j=0;
//     while(j<n){
//        if(arr[j]<0){
//         q.push(j);
//        }

//        if(j-i+1 ==k){
//             if(q.empty()) ans.push_back(0);
//             else{
//                 ans.push_back(arr[q.front()]);
//             }
//             // If the element leaving the window (at index i) is the one at the front of the queue
//             if(!q.empty() && i==q.front()){
//                 q.pop();
//             }
//             i++;
//        }
//        j++;
//     }
//     return ans;
// }
vector<int> firstneg(vector<int>&arr,int k){
    int n=arr.size();
    int left=0;
    int right=0;
    vector<int>ans;
    queue<int>q;
    while(right<n){
        if(arr[right]<0){
        q.push(right);
        }
        if(right-left+1 <k){
            right++;
        }
        else if(right-left+1 ==k){
            if(q.empty()) ans.push_back(0);
            else{
                ans.push_back(arr[q.front()]);
            }
            if(!q.empty() && q.front()==left) q.pop();
            left++;
            right++;
        }

    }
    return ans;
}


int main(){
    int k=3;
    vector<int>arr={1,3,-4,-5,8,9};
    vector<int>ans=firstneg(arr,k);
    for(const auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}