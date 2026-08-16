// Given an array arr[] of positive integers and 
// an integer k, Your task is to 
// return k largest elements in decreasing order. 
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>minH;
        vector<int>ans(k,-1);
        //vector<int>ans;
        for(int i=0;i<arr.size();i++){
            minH.push(arr[i]);
            if(minH.size()>k) minH.pop();
        }
        int i=k-1;
        while(minH.size()!=0){
        //   ans.push_back(minH.top());
        //   minH.pop();  
                ans[i]=minH.top();
                minH.pop();
                i--;
        }
      //sort(ans.rbegin(), ans.rend());
      //reverse(ans.begin(),ans.end());
        return ans;
    }
};


int main(){

  Solution s;
  vector<int>arr={1,7,3,5,4};
  int k=3;
  vector<int>ans= s.kLargest(arr,k);

 for(auto x:ans){
  cout<<x<<" ";
 }
 cout<<endl;

}