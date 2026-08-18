#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string news="";
        for(int i=0;i<n;i++){
            if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                news+= tolower(s[i]);
            }
          else if(s[i]>='0' && s[i]<='9'){ 
            news+=s[i];
        }
        }
        int _n=news.length();
        int l=0;
        int h=_n-1;
        while(l<h){
           if(news[l]!=news[h]) return false;
           l++;
           h--;
        }
        return true;
    }
};
// @lc code=end

