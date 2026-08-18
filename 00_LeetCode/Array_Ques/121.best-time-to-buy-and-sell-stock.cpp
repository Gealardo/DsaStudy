
#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
              buy=min(buy,prices[i]);
              int profit=prices[i]-buy;
              max_profit=max(max_profit,profit);
        }
        return max_profit;     
    }
};
// @lc code=end

