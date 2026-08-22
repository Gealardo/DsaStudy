#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    
       int reverse(int x) {
        long long rev = 0;
        
        while (x != 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        
        // Check if the reversed 64-bit integer fits in a 32-bit signed integer
        if (rev < INT_MIN || rev > INT_MAX) {
            return 0;
        }
        
        return rev;
    }
};
// @lc code=end

