
#include<bits/stdc++.h>
using namespace std;

//Applicable only in complete row and col both sorted ....


bool searchMatrix(vector<vector<int>>&m,int k ){

    if(m.size()==0 || m[0].size()==0) return false;

    int c=m[0].size()-1;
    int r=0;
    while(r<=m.size()-1 && c>=0){
        if(m[r][c]==k) return true;
        if(m[r][c]>k) c--;
        else r++;
    }
    return false;
}








int main() {
    vector<vector<int>> m = {
        {1,  4,  7, 11},
        {2,  5,  8, 12},
        {3,  6,  9, 16},
        {10, 13, 14, 17}
    };

    cout << "Search 5: " << searchMatrix(m, 5) << " (Expected: 1)\n";
    cout << "Search 20: " << searchMatrix(m, 20) << " (Expected: 0)\n";
    cout << "Search 1: " << searchMatrix(m, 1) << " (Expected: 1)\n";
    cout << "Search 17: " << searchMatrix(m, 17) << " (Expected: 1)\n";

    return 0;
}