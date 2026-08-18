#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:

   bool valid(string &s,int &l,int &h,int n){
     
      while(l<=h){
         if(s[l]!=s[h]){
            return false;
         }
         l++;
         h--;
      }
      return true;


   }
   
    bool validPalindrome(string s) {
        int n=s.length();
        int l=0;
        int h=n-1;
       
        bool x=valid(s,l,h,n);
        if(x) return true;
        int _l=l;
        int _h=h;
        if(x==false){
            if(l+1 <n) {
                l++;
                bool x2=valid(s,l,h,n);
                if(x2) return true;
            }
            if(_h-1 >=0) {
                _h--;
                bool x3=valid(s,_l,_h,n);
                if(x3) return x3;
            }
        }
        return false;
    }
};
// @lc code=end

