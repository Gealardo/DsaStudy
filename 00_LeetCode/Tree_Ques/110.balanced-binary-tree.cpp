
#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

//  Definition for a binary tree node.
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
    
  int bal(TreeNode*&root,bool &isbal)
  { 
    if(root==nullptr) return 0;

    int leftcheck=bal(root->left,isbal);
    int rightcheck=bal(root->right,isbal);
    if(rightcheck-leftcheck>1 || rightcheck-leftcheck<(-1)){
        isbal=false;
    }
    return 1+max(leftcheck,rightcheck);
  }
  

    bool isBalanced(TreeNode* root) {
       
        bool isYes=true;
        bal(root,isYes);
        return isYes;

    }
};
// @lc code=end

