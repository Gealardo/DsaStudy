#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        if(n1!=n2) return false;
        unordered_map<char,int>mp;
        for(int i=0;i<n1;i++){
            mp[s[i]]++;
        }
        for(int j=0;j<n2;j++){
            if(mp.find(t[j])==mp.end()){
                return false;
            }
            else{
                mp[t[j]]--;
                if(mp[t[j]]==0) mp.erase(t[j]);
            }
        }
        if(mp.empty()) return true;
        else return false;
    }
};
// @lc code=end

