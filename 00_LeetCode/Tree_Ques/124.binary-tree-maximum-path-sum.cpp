#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
// @lc code=start

class Solution {
public:
   // concept simmilar to (height + diameter ), polishing is neglect it negative

   int maxSum(TreeNode* &root,int &ans) {
        
        if(root==nullptr) return 0;

        int left=max(0,maxSum(root->left,ans));
        int right=max(0,maxSum(root->right,ans));
        
        ans=max(ans,left+right+root->val);

        return (root->val)+max(left,right);

    }
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;

        maxSum(root,ans);

        return ans;

    }
};
// @lc code=end

