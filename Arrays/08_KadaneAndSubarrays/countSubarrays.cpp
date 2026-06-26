#include<bits/stdc++.h>
using namespace std;

// Count total number of subarrays - O(1) Time!
long long countSubarrays(int n) {
    
    // n even -> n/2 * (n+1) || odd -> (n+1)/2 * n; do separetly
    return (long long)n*(n+1)/2; 
}

int main() {
    // Test Case 1
    int n1 = 3;
    cout << "Array of size " << n1 << " has " << countSubarrays(n1) << " subarrays (Expected: 6)\n";
    
    // Test Case 2
    int n2 = 4;
    cout << "Array of size " << n2 << " has " << countSubarrays(n2) << " subarrays (Expected: 10)\n";
    
    // Test Case 3: Large number (watch out for overflow!)
    int n3 = 100000;
    cout << "Array of size " << n3 << " has " << countSubarrays(n3) << " subarrays (Expected: 5000050000)\n";
    
    // Test Case 4: Edge case
    int n4 = 1;
    cout << "Array of size " << n4 << " has " << countSubarrays(n4) << " subarrays (Expected: 1)\n";
    
    return 0;
}