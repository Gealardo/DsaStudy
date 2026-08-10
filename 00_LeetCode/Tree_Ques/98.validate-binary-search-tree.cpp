#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

    bool isBts(TreeNode*& root,long long mini,long long maxi){
        if(root==nullptr) return true ;

        if(root->val<=mini || root->val>=maxi) return false;

        bool left=isBts(root->left,mini,root->val);

        bool right=isBts(root->right,root->val,maxi);

        return left && right;

    }

    bool isValidBST(TreeNode* root) {
        
       return isBts(root , LLONG_MIN,LLONG_MAX);

    }
};
// @lc code=end

