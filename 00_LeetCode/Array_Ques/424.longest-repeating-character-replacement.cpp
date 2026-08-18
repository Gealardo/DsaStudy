#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        
       int n=s.length();
       int l=0;
       int r=0;
       int maxlen=0;
       int maxfreq=0;
       
       vector<int>count(26,0);

       for(int r=0;r<n;r++){

        count[s[r]-'A']++;
     
        maxfreq=max(maxfreq,count[s[r]-'A']);

        if((r-l+1) - maxfreq >k){
            count[s[l] - 'A']--;
            l++;
        }
        
        // Update the maximum length found so far
        maxlen = max(maxlen, r - l + 1);

       }
       return maxlen;
     
    }
};
// @lc code=end

