#include<bits/stdc++.h>
using namespace std;

void subsequences(int idx,vector<int>&arr,vector<int>&ans){


    //base case ->print   [.  .  .] print
    //                     i->i->i -> i
     if(idx==arr.size()){
        // for empty subseq..
        if(ans.empty()) cout<<"{}";
        for(const auto x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
     }
    // pick ->push
    ans.push_back(arr[idx]);
    subsequences(idx+1,arr,ans);

    //backtrack->  pop
    ans.pop_back();

    // not pick ->just skip and move on to next index
    subsequences(idx+1,arr,ans);
}
int main(){
    vector<int>arr={1,2,3};
    vector<int>ans;
    subsequences(0,arr,ans);
}

/*

                 []
             /        \
         [1]             []
       /    \           /    \
    [1,2]    [1]       [2]     []
    /    \    /   \    /  \    / \
[1,2,3] [1,2][1,3] [1][2,3][2][3] []


*/