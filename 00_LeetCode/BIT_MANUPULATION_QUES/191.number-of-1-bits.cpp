#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:

    int hammingWeight(int n) {
        int x=0;
        for(int i=0;i<32;i++){
            if(n>>i & 1) x++;
        }
        return x;
    }
};
// @lc code=end

