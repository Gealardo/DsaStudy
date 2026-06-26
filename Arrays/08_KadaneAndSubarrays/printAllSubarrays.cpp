#include<bits/stdc++.h>
using namespace std;
 int maxSum=INT_MIN;
void allsubArray(vector<int>nums){
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            cout<<"[";
            for(int k=i;k<=j;k++){
                cout<<nums[k];
            }
            cout<<"]";
        }
    }
}

int main(){
    vector<int> nums = {-3, -5, -2, -9};
    allsubArray(nums);
    
   
    
    return 0;
}
