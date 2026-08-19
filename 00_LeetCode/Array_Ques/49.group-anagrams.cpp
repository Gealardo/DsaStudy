#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>>ans;
            unordered_map<string,vector<string>>mp;
        for(auto &s:strs){
             string temp=s;
             sort(temp.begin(),temp.end());
             mp[temp].push_back(s);
        }
        for(auto s:mp){
             ans.push_back(s.second);
        }
        return ans;
        
    }
};
// @lc code=end

