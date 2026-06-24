#include<bits/stdc++.h>
using namespace std;

// Search in ONLY row-wise sorted matrix
bool searchRowWise(vector<vector<int>>& m, int target) {
    
    if(m.empty()) return false;
    for(int r=0;r<m.size();r++){
        int i=0;
        int j=m[0].size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(m[r][mid]==target) return true;
            else if(m[r][mid]>target) j=mid-1;
            else i=mid+1; 
        }
    }
   
    return false;
}

int main() {
    
    vector<vector<int>> m = {
        {1,  5,  9},
        {10, 11, 13},
        {2,  6,  8} 
    };

    cout << "Search 13: " << searchRowWise(m, 13) << " (Expected: 1)\n";
    cout << "Search 7: " << searchRowWise(m, 7) << " (Expected: 0)\n";

    return 0;
}