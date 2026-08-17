#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
      
public:
  
   struct lemda{
      bool operator()(const pair<char,int>&a,const pair<char,int>&b){
           return a.second < b.second;                 
      }
       
   };
    string frequencySort(string s) {
        
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        priority_queue< pair<char,int> ,vector<pair<char,int>>, lemda >pq;
        for(const auto &entry: mp ){
            pq.push(entry);
        }
        string result="";
        while(!pq.empty()){
            int freq=pq.top().second;
            char charecter=pq.top().first;
            pq.pop();
            result.append(freq,charecter);
        }
        return result;

    }
};
// @lc code=end

