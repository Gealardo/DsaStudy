//make row/col zero if they contains even single zero

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       vector<bool>row(matrix.size(),false);
       vector<bool>col(matrix[0].size(),false);

     
       for(int r=0;r<matrix.size();r++){
         for(int c=0;c<matrix[0].size();c++){

               if(matrix[r][c]==0){
                row[r]=true;
                col[c]=true;
               }

         }
       }
       
       for(int r=0;r<matrix.size();r++){
         for(int c=0;c<matrix[0].size();c++){
               if(row[r]==true ){
                matrix[r][c]=0;
               }

              if(col[c]==true ){
                matrix[r][c]=0;
               }

         }
       }

    }

    void optimal(vector<vector<int>>&m){
      bool firstrow_zero=false;
      bool firstcol_zero=false;
   // Check first row
     for(int j = 0; j < m[0].size(); j++) {
        if(m[0][j] == 0) {
        firstrow_zero = true;
        break;
    }
}

// Check first column  
     for(int i = 0; i < m.size(); i++) {
       if(m[i][0] == 0) {
        firstcol_zero = true;
        break;
    }
}

// Mark zeros in inner matrix
    for(int i = 1; i < m.size(); i++) {
       for(int j = 1; j < m[0].size(); j++) {
        if(m[i][j] == 0) {
            m[i][0] = 0;
            m[0][j] = 0;
        }
    }
}           

     for(int i=1;i<m.size();i++){
        for(int j=1;j<m[0].size();j++){
            if(m[0][j]==0 || m[i][0]==0 ){
                m[i][j]=0;
            }

        }
     }
     if(firstrow_zero) {
    for(int j = 0; j < m[0].size(); j++) {
        m[0][j] = 0;
    }
}
if(firstcol_zero) {
    for(int i = 0; i < m.size(); i++) {
        m[i][0] = 0;
    }
}
      
    }
};

// Helper function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    int m, n;
    
    // Read dimensions
    cout << "Enter rows and columns: ";
    cin >> m >> n;
    
    // Read matrix
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Call solution
    Solution sol;
    sol.optimal(matrix);
    
    // Print result
    cout << "\nResult:\n";
    printMatrix(matrix);
    
    return 0;
}