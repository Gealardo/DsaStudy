#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 */

// @lc code=start
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({piles[i],i});
        }
        while(k--){
           int idx=pq.top().second;
           piles[idx]=piles[idx]-(piles[idx]/2);
           pq.pop();
           pq.push({piles[idx],idx});
        }  
        
        int sum=0;
        for(const auto x:piles){
            sum+=x;
        }
        return sum;
    }
};
// @lc code=end

