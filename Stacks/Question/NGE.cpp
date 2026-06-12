// next greatest integer in an int array for each element
#include<bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n,-1);
    stack<int>st;
for(int curr=0;curr<n;curr++){
    while(!st.empty() && nums[curr]>nums[st.top()]){
          ans[st.top()]=nums[curr];
          st.pop();
  
    }
    st.push(curr);

   
}
 return ans;
}

int main(){
    

    vector<int> nums = {4, 5, 2, 25};
    vector<int> result = nge(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}