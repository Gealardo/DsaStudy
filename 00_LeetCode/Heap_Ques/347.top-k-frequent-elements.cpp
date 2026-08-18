#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
  struct lemda{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
          return a.second > b.second;
    }
  };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,lemda>pq;
        
        for(auto i:mp){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
        
    }
};
// @lc code=end

