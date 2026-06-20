#include<bits/stdc++.h>
using namespace std;

int minSubArray(vector<int>& arr, int target) {
    int n = arr.size();
    int left = 0, right = 0;
    int sum = 0;
    int minLength = INT_MIN;
    
    while (right < n) {
        sum += arr[right];
        while(sum >= target) {
            minLength = max(minLength, right - left + 1);
            sum -= arr[left];
            left++;
        }
        right++;
    }
    
    return minLength == INT_MAX ? 0 : minLength;
}
int main(){
    int target=3;
    vector<int>arr={1,3,-4,-5,8,9};
    int length=minSubArray(arr,target);
    cout<<length<<endl;
}