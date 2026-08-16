#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    //  int last(vector<int>& stones) {
    //     while(stones.size()>1){

    //         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //         for(int i=0;i<stones.size();i++){
    //             pq.push({stones[i],i});
    //             if(pq.size()>2) pq.pop();
    //         }
    //         int secondLar=pq.top().first;
    //         int i1=pq.top().second;

    //         pq.pop();

    //         int largest=pq.top().first;
    //         int i2=pq.top().second;

    //         pq.pop();
            
    //         int x=abs(secondLar-largest);
            
    //         int higher=max(i1,i2);
    //         int lower=min(i1,i2);

    //         stones.erase(stones.begin()+higher);
    //         if(x==0){
    //              stones.erase(stones.begin()+lower);
    //         }
    //         else{
    //             stones[lower]=x;
    //         }          
    //     }  
    //      if (stones.empty()) return 0; 
    //     int ans=stones[0];
    //     return ans;     
    // }   

    int lastStoneWeight(vector<int>& stones) {
       // return last(stones);
        
       priority_queue<int>pq;

       for(int i=0;i<stones.size();i++){
        pq.push(stones[i]);
       }

       while(pq.size()>1){
           int first=pq.top();
           pq.pop();
           int second=pq.top();
           pq.pop();
           pq.push(first-second);
       }
       
       return pq.top();

    }
};
// @lc code=end

