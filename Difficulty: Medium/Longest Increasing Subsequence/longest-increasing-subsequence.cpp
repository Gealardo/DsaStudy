class Solution {
  public:
    int lis(vector<int>& arr) {
       vector<int>temp;
       int n=arr.size();
       int  l=0;
       for(int i=0;i<n;i++){
           if(temp.empty()||arr[i]>temp.back()){
               temp.push_back(arr[i]);
               l++;
           } 
           else{
               auto lb=lower_bound(temp.begin(),temp.end(),arr[i]);
               *lb=arr[i];
           }
       }
       return l;
    }
};