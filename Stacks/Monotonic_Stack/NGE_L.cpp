#include<bits/stdc++.h>
using namespace std;


vector<int> Next_Smaller_element_to_left(const vector<int>&arr){
  int n=arr.size();
  vector<int>ans(n,-1);
  stack<int>st;
  for(int i=0;i<n;i++){
    
    while(!st.empty() && arr[i]>arr[st.top()]){
      st.pop();
    }
    if(!st.empty()) ans[i]=arr[st.top()];
    st.push(i);
  }
  return ans;

}
int main(){
  vector<int>arr={1,6,2,4,9,0};
  vector<int>ans=Next_Smaller_element_to_left(arr);
  for( const auto x: ans){
        cout<<x<<" ";
  }
  cout<<endl;
}