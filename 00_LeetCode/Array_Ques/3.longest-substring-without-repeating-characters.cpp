#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        int r=0;
        int maxlen=0;
        unordered_map<char,int>mp;
        while(r<n){

          mp[s[r]]++;
          while(mp[s[r]]>1){
            mp[s[l]]--;
            if(mp[s[l]]==0) mp.erase(mp[s[l]]);
            l++;
          }

          maxlen=max(maxlen, r - l + 1);
          r++;
        }
        
        return maxlen;
    }
};
// @lc code=end

