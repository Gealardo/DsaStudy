#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum_el(vector<int>&arr,int k){
    vector<vector<int>>result;
    //step 1: sort the arr
    //step 2: inside the for loop decide the target
    //apply 2 sum technique to find other two elements
    //remove duplicates->two types
    // 1->finding two element by two sum while(i+1<j && arr[i]==arr[i+1] do i++),while(j-1>iarr[j]==arr[j-1] do j--) 
    //2->fixing the element for target if(i-1>=0 && arr[i]==arr[i-1]) 
     sort(arr.begin(), arr.end());
     int n=arr.size();
     for(int i=0;i<n-2;i++){
        // el1 + el2 + el3 = k
        if(i-1 >=0 && (arr[i]==arr[i-1])){
           continue;
        }
        int el1=arr[i];
        int target=k-el1;
        int left=i+1;
        int right=n-1;

        while(left<right){
            
            if(arr[left]+arr[right]>target) right--;
            else if(arr[left]+arr[right]< target) left++;
            else{
               vector<int>triplets={el1,arr[left],arr[right]};
               result.push_back(triplets);
               while(left+1 < right && arr[left]==arr[left+1]) left++;
               while(right-1 >left && arr[right]==arr[right-1]) right--;
               left++ ; right--;
            } 
        }
         
     }


    return result;
}

int main(){
    vector<int>arr={1,3,-1,0,-1,8};
    int target=0;
    vector<vector<int>>result=threesum_el(arr,target);
    for (const auto& row : result) {
       cout<<"(";
       for (int num : row) {
              cout << num << " ";
        }
        cout<<")";
}
    
}