#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1985 lang=cpp
 *
 * [1985] Find the Kth Largest Integer in the Array
 */

// @lc code=start
class Solution {
public:

   struct Compare{

      bool operator()(const string &a, const string &b){
          // fro min , a-> curr coming 
          // b-> just before exinsting 
          // after comparing if true a goes to below b otherwise ...
          if(a.length()>b.length()) return true;

          else if(a.length()<b.length()) return false;
              
          else return a>b ;

      }


   };


    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
        priority_queue<string,vector<string>, Compare>pq;
        for(int i=0;i<n;i++){

            pq.push((nums[i]));

            if(pq.size()>k) pq.pop();
        }

        string s=(pq.top());
        return s;
    }
};
// @lc code=end

