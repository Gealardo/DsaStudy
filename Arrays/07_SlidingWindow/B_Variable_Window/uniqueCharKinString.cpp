#include<bits/stdc++.h>
using namespace std;


int fun(string s,int k){
    int n=s.length();
    int left=0,right=0;
    int max_len=0;
    unordered_map<char,int>mp;
    while(right<n){
        mp[s[right]]++;

        while(mp.size()>k){
            mp[s[left]]--;
            if(mp[s[left]]==0) mp.erase(s[left]);
            left++;
        }
        max_len=max(max_len,right-left+1);
        right++;
    }
    return max_len;
}

int main(){
    string s="aaaaaaabbbbc";
  int t1=fun(s,3);
  cout<<t1<<endl;
}