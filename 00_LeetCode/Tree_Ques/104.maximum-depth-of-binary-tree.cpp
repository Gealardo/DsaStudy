#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
   
    int height(TreeNode*& root){

        if(root==NULL) return 0;
        int leftheight=height(root->left);
        int rightheight=height(root->right);

        return 1+ max(leftheight,rightheight);

    }

    int maxDepth(TreeNode* root) {
        return height(root);
    }
};
// @lc code=end

