#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>&arr,int k){
    vector<vector<int>>result;
     sort(arr.begin(), arr.end());
     int n=arr.size();
     for(int i=0;i<n-3;i++){
        // el1 + el2 + el3 + el4 = k
        if(i-1 >=0 && (arr[i]==arr[i-1])){
           continue;
        }
        int el1=arr[i];
         for(int j=i+1;j<n-2;j++){
           if(j > i+1 && arr[j]==arr[j-1]) continue;
           int el2=arr[j];
           long long target = (long long)k - el1 - el2;
           int left=j+1;
           int right=n-1;

        while(left<right){
            
            if(arr[left]+arr[right]>target) right--;
            else if(arr[left]+arr[right]< target) left++;
            else{
               vector<int>fourfer={el1,el2,arr[left],arr[right]};
               result.push_back(fourfer);
               while(left+1 < right && arr[left]==arr[left+1]) left++;
               while(right-1 >left && arr[right]==arr[right-1]) right--;
               left++ ; right--;
            } 
        }
         
     }
    }


    return result;
}

int main(){
    vector<int>arr={1,3,-1,0,-1,8 ,1};
    int target=0;
    vector<vector<int>>result=fourSum(arr,target);
    for (const auto& row : result) {
       cout<<"(";
       for (int num : row) {
              cout << num << " ";
        }
        cout<<")";
}
    
}