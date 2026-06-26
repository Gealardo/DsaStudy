#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size();      // Rows of A
    int n = A[0].size();   // Cols of A = Rows of B
    int p = B[0].size();   // Cols of B
    if (n != B.size()) {
    cout << "Error: A's columns (" << n 
         << ") must equal B's rows (" << B.size() << ")\n";
    return {};
}
    
//------------------------------------------------
   vector <vector<int> >C(m, vector<int>(p,0));

   for(int i=0;i<m;i++){
    for(int j=0;j<p;j++){
        for(int k=0;k<n;k++){
        C[i][j]+=A[i][k]*B[k][j];
        }
    }
   }

   return C;



//------------------------------------------------
}
void printMatrix(const vector<vector<int>>& mat) {
    for(auto row : mat) {
        for(int x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    vector<vector<int>> B = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    
    cout << "Matrix A (2x3):\n";
    printMatrix(A);
    
    cout << "\nMatrix B (3x2):\n";
    printMatrix(B);
    
    vector<vector<int>> C = multiply(A, B);
    
    cout << "\nResult C = A × B (2x2):\n";
    printMatrix(C);
    // Expected:
    // 22 28
    // 49 64

    return 0;
}