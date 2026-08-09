
#include<bits/stdc++.h>
using  namespace std;

/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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

    int height(TreeNode*& root,int &d){

        if(root==nullptr) return 0;
        int leftheight=height(root->left,d);
        int rightheight=height(root->right,d);
        d=max(d,leftheight+rightheight);
        return 1+ max(leftheight,rightheight);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        height(root,d);
        return d;
    }
};
// @lc code=end

