#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */
 //* Definition for a binary tree node.
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

    TreeNode* invert(TreeNode* &root){
        if(root==nullptr) return NULL;
        TreeNode* rootleft=invert(root->left);
        TreeNode* rootright=invert(root->right);
        root->left=rootright;
        root->right=rootleft;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        
       return invert(root);
    }
};
// @lc code=end

