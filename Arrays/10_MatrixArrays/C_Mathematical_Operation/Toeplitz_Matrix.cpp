#include<bits/stdc++.h>
using namespace std;


bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Start from (1, 1) and check diagonal predecessor
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] != matrix[i-1][j-1]) {
                return false;  // Found a mismatch!
            }
        }
    }
    
    return true;  // All diagonals are valid!
}


int main(){

     vector<vector<int>>m={
       {1,2,3},
       {4,1,2},
       {5,4,1},

    };
    bool x=isToeplitzMatrix(m);
    cout<<x<<endl;

}