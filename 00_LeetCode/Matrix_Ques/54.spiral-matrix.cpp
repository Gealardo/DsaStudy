#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
     vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        int top=0;   int left=0;    int right=m-1;    int bottom=n-1;
        while(top<=bottom && left <= right){

            int l=left;
            while(l<=right){
                ans.push_back(matrix[top][l]);
                l++;
            }
            top++;
            if(top<=bottom){
                int t=top;
                while(t<=bottom){
                   ans.push_back(matrix[t][right]);
                   t++;
                }
            }
            right--;
            if(top <= bottom && left <= right){
                int r=right;
                while(r>=left){
                    ans.push_back(matrix[bottom][r]);
                    r--;
                }
            }
            bottom--;
            if(top <= bottom && left <= right){
                int b=bottom;
                while(b>=top){
                    ans.push_back(matrix[b][left]);
                    b--;
                }
            }
            left++;
        }
        return ans;       
    }
};
// @lc code=end

