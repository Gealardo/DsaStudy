#include<bits/stdc++.h>
using namespace std;

// recursive...approch
int uniquePath2(int m, int n){
    if(m<0||n<0) return 0;
    if(m==1 || n==1) return 1; 
    return uniquePath2(m-1,n )+uniquePath2(m,n-1);
}




// recursive + memoization approch  !!!!!!!..need impro...!!!!
int uniquePath_memo(int m, int n, vector<vector<int>>& dpmemo) {
    // Base cases
    if (m < 1 || n < 1) return 0;
    if (m == 1 || n == 1) return dpmemo[m][n] = 1;
    
    // Return cached result
    if (dpmemo[m][n] != -1) return dpmemo[m][n];
    
    // Recurrence: paths from top + paths from left
    return dpmemo[m][n] = uniquePath_memo(m - 1, n, dpmemo) 
                        + uniquePath_memo(m, n - 1, dpmemo);
}
int uniquePathmemo(int m, int n) {
    // m+1 and n+1 for 1-based indexing
    vector<vector<int>> dpmemo(m + 1, vector<int>(n + 1, -1));
    return uniquePath_memo(m, n, dpmemo);
}





// tabulation approch..
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {  
           dp[i][j]=dp[i-1][j]+dp[i][j-1];  
        }
    }
    return dp[m-1][n-1];
}





int main() {
    cout << "Test 1 (3x2): " << uniquePaths(3, 2) << " (Expected: 3)\n";
    cout << "Test 2 (3x3): " << uniquePaths(3, 3) << " (Expected: 6)\n";
    cout << "Test 3 (7x3): " << uniquePaths(7, 3) << " (Expected: 28)\n";
    cout<<endl;
    cout<<uniquePath2(7,3)<<endl;

    int m1 = 3, n1 = 7;
    cout << "Grid " << m1 << "*" << n1 
         << "  Unique Paths: " << uniquePathmemo(m1, n1) 
         << " (Expected: 28)\n";
    return 0;
}