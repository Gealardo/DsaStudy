class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        vector<int>dp;
        dp.push_back(arr[0]);
        int l=1;
        for(int i=1;i<n;i++){
            if( arr[i] > dp.back() ){
                dp.push_back(arr[i]);
                l++;
            } 
            else{
                auto idx = lower_bound(dp.begin(),dp.end(),arr[i]);
                *idx = arr[i];
            }
        }
        return n-l;
    }
};