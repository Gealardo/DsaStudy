#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
// @lc code=start


class Solution {
public:
    
     TreeNode* lowest(TreeNode* &root, TreeNode*& p, TreeNode*& q) {
        if(root==nullptr) return nullptr;

        if(root->val<p->val && root->val<q->val){
           return lowest(root->right,p,q);
        }
        else if(root->val>p->val && root->val>q->val){
            return lowest(root->left,p,q);
        }
        else return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowest(root,p,q);
    }
};
// @lc code=end

