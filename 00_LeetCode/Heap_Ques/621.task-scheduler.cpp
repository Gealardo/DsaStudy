#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
     struct lemda{
        bool operator()(const pair<char,int>&a,const pair<char,int>&b){
            return a.second< b.second;
        }
     };
    int leastInterval(vector<char>& tasks, int n) {
        int time=0;
        unordered_map<char,int>mp;
        for(auto c:tasks){
            mp[c]++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,lemda >pq;
        for(auto entry:mp){
            pq.push(entry);
        }
        while(!pq.empty()){
           
           vector<pair<char,int>>t;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                auto temp=pq.top();
                pq.pop();
                temp.second--;
                t.push_back(temp);
                
            }
        }
            for(auto &freq:t){
                if(freq.second >0) pq.push(freq);
            }
            if(pq.empty()){
               time+=t.size();
            }else{
                time+=n+1;
            }
        
    }
    return time;
   }
};
// @lc code=end

