class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        if(n==1) return arr[0];
        vector<int>temp(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            temp[i] = arr[i]; 
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    temp[i] = max(temp[i],arr[i]+temp[j]);
                }
                
            }
             sum=max(sum,temp[i]);
        }
        return sum;
    }
};