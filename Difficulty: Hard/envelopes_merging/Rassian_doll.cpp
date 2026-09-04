class Solution {
public:
    struct lemda{
        bool operator()(vector<int>&a,vector<int>&b){
            if (a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        }
    };
    int LIS(vector<vector<int>>& envelopes){
       int n=envelopes.size();
       if(n==0) return 0;
       vector<int>temp;
       temp.push_back(envelopes[0][1]);
       int l=1;
       for(int i=1;i<n;i++){
           if(temp.back()<envelopes[i][1]){
               temp.push_back(envelopes[i][1]);
               l++;
            }
            else{
                auto idx=lower_bound(temp.begin(),temp.end(),envelopes[i][1]);
                *idx=envelopes[i][1];
            }
         }
         return l;
       }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),lemda());
        return LIS(envelopes);
    }
};
