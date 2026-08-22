#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
     int count(int n){
        int x=0;
        for(int i=0;i<32;i++){
            if(n>>i & 1) x++;
        }
        return x;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(count(i));
        }
        return ans;
    }
};
// @lc code=end

